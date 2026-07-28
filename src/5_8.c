#include <stdio.h>

int main() {
    int m,n,i,j,k,h,l;
    int t=0;
    scanf("%d %d",&m,&n);
    int a[m][n];
    for (i=0;i<m;i++) {
        for (j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0;i<m;i++) {
        int max=a[i][0];
        l=0;
        for (j=1;j<n;j++) {
            if (a[i][j]>max) {
                max=a[i][j];
                l=j;
            }
        }
        int min=a[0][l];
        h=0;
        for (k=1;k<m;k++) {
            if (a[k][l]<min) {
                min=a[k][l];
                h=k;
            }
        }
        if (max==min && h==i) {
            printf("A[%d][%d]=%d是鞍点",i,l,a[i][l]);
            t=1;
            break;
        }
    }
    if (t==0) {
        printf("没有鞍点");
    }
    return 0;
}