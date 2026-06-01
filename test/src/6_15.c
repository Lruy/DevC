#include <stdio.h>
#include <stdlib.h>

int htoi(char *a) {
    return strtol(a,NULL,16);
}

int main() {
    char a[9];
    gets(a);
    int i= htoi(a);
    printf("%d",i);
    return 0;
}