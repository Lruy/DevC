#include <stdio.h>

int main() {
    int x,i,j;
    scanf("%d",&x);
    int a[x+1];
    for(i=0;i<x+1;i++) {
        scanf("%d",&a[i]);
    }
    for(j=0;j<x+1;j++) {
        for(i=0;i<x+1;i++) {
            if (a[i]>a[i+1]) {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    for(i=0;i<x+1;i++) {
        printf("%d ",a[i]);
    }
}