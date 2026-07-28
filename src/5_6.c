#include <stdio.h>

int main() {
    int b,i,j,x;
    scanf("%d",&b);
    int a[b];
    for(i=0;i<b;i++) {
        a[i]=0;
    }
    for(i=0;i<b;i++) {
        a[i]=1;
        for(j=i-1;j>0;j--) {
            a[j]+=a[j-1];
        }
        for (x=0;x<i+1;x++) {
            printf("%d ",a[x]);
        }
        printf("\n");
    }
}