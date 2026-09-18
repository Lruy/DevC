#include <stdio.h>

void move(int n,int m,int *a) {
    int temp,i;
    int b[n];
    for (i=0;i<m;i++) {
        b[i]=a[n-m+i];
    }
    for (i=m;i<n;i++) {
        b[i]=a[i-m];
    }
    for (i=0;i<n;i++) {
        printf("%d ",b[i]);
    }
}

int main() {
    int n,m,i;
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    move(n,m,a);
}