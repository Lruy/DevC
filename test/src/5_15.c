#include <stdio.h>

int main() {
    int i,j;
    char a[2][21];
    gets(a[0]);
    for(i=0;i<21;i++) {
        a[1][i]=a[0][i];
        if (a[0][i]=='\0')break;
    }
    puts(a[1]);
    return 0;
}