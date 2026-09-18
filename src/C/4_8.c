#include <stdio.h>

int main() {
    int a=100;
    for (;a!=999;a++) {
        int f=a/100;
        int s=a/10-f*10;
        int t=a-f*100-s*10;
        if (f*f*f+s*s*s+t*t*t==a)printf("%d\n",a);
    }
    return 0;
}