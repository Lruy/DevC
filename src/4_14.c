#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d",&a);
    for (b=a;b!=0;) {
        b--;
        for (c=0;c!=b;c++) {
            printf(" ");
        }
        for (c=0;c!=2*(a-b)-1;c++) {
            printf("*");
        }
        for (c=0;c!=b;c++) {
            printf(" ");
        }
        printf("\n");
    }
    for (b=0;b!=a-1;) {
        b++;
        for (c=0;c!=b;c++) {
            printf(" ");
        }
        for (c=0;c!=2*(a-b)-1;c++) {
            printf("*");
        }
        for (c=0;c!=b;c++) {
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}