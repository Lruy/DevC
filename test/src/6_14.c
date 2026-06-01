#include <stdio.h>
#include <string.h>

char name[11][9999];
int num[11];
int i,j;

void read() {
    for(i=0;i<10;i++) {
        scanf("%s",name[i]);
        scanf("%d",&num[i]);
    }
}

void sortbyno() {
    for(i=0;i<9;i++) {
        for (j=0;j<9-i;j++) {
            if (num[j]>num[j+1]) {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
                char tempname[9999];
                strcpy(tempname,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],tempname);
            }
        }
    }
}

int search(int a) {
    int low=0;
    int high=9;
    while(low<=high) {
        int mid=(low+high)/2;
        if(a==num[mid]) {
            return mid;
        }
        if (a<num[mid]) {
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
}

int main() {
    int x;
    read();
    sortbyno();
    for(x=0;x<10;x++) {
        printf("%d ",num[x]);
        printf("%s\n",name[x]);
    }
    scanf("%d",&x);
    if(search(x)!=-1) {
        printf("%s",name[search(x)]);
    }
    else {
        printf("没有匹配的职工");
    }
}