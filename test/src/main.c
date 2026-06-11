#include <stdio.h>

const int MAXN = 10;
int main() {
    int a[MAXN+5];
    int maxinput=0;
	for(int i=0;i<MAXN;i++){
        scanf("%d",&a[i]);
        if(a[i]>maxinput)maxinput=a[i];
    }
    for(int i=maxinput;i>=0;i--){
        if(i){
            if(i%5 || !i)printf("  ");
            else printf("%d ",i);   
            printf("|");
            for(int j=0;j<MAXN;j++){
                if(a[j]>=i)printf(" #");
                else printf("  ");
            }
            printf("\n");
        }
        else{
            printf("  +");
            for(int j=0;j<MAXN;j++){
                printf("--");
            }
        }
    }
    return 0;
}