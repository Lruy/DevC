#include <stdio.h>
#include <string.h>

void rev_str(char *a) {
    int length = strlen(a);
    int i;
    for (i=0;i<length/2;i++) {
        char temp = a[i];
        a[i] = a[length-1-i];
        a[length-1-i] = temp;
    }
}

int main() {
    char a[101];
    gets(a);
    rev_str(a);
    printf("%s",a);
    return 0;
}