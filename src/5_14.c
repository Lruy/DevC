#include <stdio.h>

int main() {
    int i,j,t=0,o=0;
    char a[2][20];
    for (i=0;i<2;i++) {
        gets(a[i]);
    }
    for (j=0;a[1][j]!='\0' && a[0][j]!='\0';j++) {
        if (a[0][j]!=a[1][j]) {
            o=a[0][j]-a[1][j];
            t=1;
            printf("%d",o);
            return 0;
        }
    }
    if (t==0 && j<20) printf("%d",a[0][j]-a[1][j]);
    else printf("0");
    return 0;
}