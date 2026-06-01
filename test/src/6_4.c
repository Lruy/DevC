#include <stdio.h>

void transpose(int x[3][3]) {
    int i,j;
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            printf("%d ",x[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int i,j;
    int a[3][3];
    void transpose(int[3][3]);
    for (i=0;i<3;i++) {
        for (j=0;j<3;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    transpose(a);
}