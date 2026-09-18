#include <stdio.h>
#include <string.h>

char name[11][9999];
float score[11][6];
float stu_avg[11];
float cour_avg[6];
int i,j;
char maxname[9999];
int maxnum;
float maxscore=0;

void aver_stu() {
    for(i=0;i<10;i++) {
        stu_avg[i]=0;
        float sum=0.0;
        for(j=0;j<5;j++) {
            sum+=score[i][j];
        }
        stu_avg[i]=sum/5;
    }
}

void aver_cour() {
    for (i=0;i<5;i++) {
        cour_avg[i]=0;
        float sum=0.0;
        for (j=0;j<10;j++) {
            sum+=score[j][i];
        }
        cour_avg[i]=sum/10;
    }
}

void find_max() {
    for(i=0;i<10;i++) {
        for(j=0;j<5;j++) {
            if(maxscore<score[i][j]) {
                maxscore=score[i][j];
                strcpy(maxname,name[i]);
                maxnum=j+1;
            }
        }
    }
}

float aver_quad() {
    float sum1=0.0;
    float sum2=0.0;
    for(i=0;i<10;i++) {
        sum1+=stu_avg[i]*stu_avg[i];
    }
    sum1=sum1/10;
    for(i=0;i<10;i++) {
        sum2+=stu_avg[i];
    }
    sum2=sum2*sum2/100;
    return sum1-sum2;
}

int main() {
    for (i=0;i<10;i++) {
        scanf("%s",name[i]);
        for (j=0;j<5;j++) {
            scanf("%f",&score[i][j]);
        }
    }
    aver_stu();
    aver_cour();
    find_max();
    for (i=0;i<10;i++) {
        printf("%s ",name[i]);
        printf("%.2f\n",stu_avg[i]);

    }
    for (i=0;i<4;i++) {
        printf("%.2f ",cour_avg[i]);
    }
    printf("%.2f\n",cour_avg[4]);
    printf("%s ",maxname);
    printf("%d ",maxnum);
    printf("%.2f\n",maxscore);
    printf("%.2f",aver_quad());
}