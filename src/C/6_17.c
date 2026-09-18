#include <stdio.h>

#define MAX_LEN 11
int pos = 0;

void convert(int n, char str[]) {
    if (n / 10 != 0) {
        convert(n / 10, str);
    }
    str[pos++] = n % 10 + '0';
    str[pos] = '\0';
}

int main() {
    int n;
    char str[MAX_LEN];
    scanf("%d", &n);
    convert(n, str);
    printf("%s\n", str);
    return 0;
}