#include <stdio.h>

int main() {
    int i,j;
    char a[2][20];
    for (i=0;i<2;i++) {
        gets(a[i]);
    }
    for (i=0;i<2;i++) {
        for (j=0;j<20 && a[i][j]!='\0';j++) {
            printf("%c",a[i][j]);
        }
    }
    return 0;
}