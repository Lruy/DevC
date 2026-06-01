#include <stdio.h>
#include <string.h>

void maxword(char *a) {
    int len=0;
    char *mw=0;
    char max[1001];
    mw = strtok(a," ");
    while (mw) {
        if (strlen(mw)>len) {
            len=strlen(mw);
            strcpy(max,mw);
        }
        mw = strtok(NULL," ");
    }
    printf("%s",max);
}

int main() {
    char a[1001];
    gets(a);
    maxword(a);
    return 0;
}