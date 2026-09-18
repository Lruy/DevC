#include <stdio.h>

int main() {
    int a=1,b,c=0;
    for (;a!=1000;a++) {
        for (b=1;b<a;b++) {
            if(a%b==0)c+=b;
        }
        if (a==c) {
            printf("%d:its factors are",a);
            for (b=1;b<a;b++) {
                if (a%b==0)printf(" %d",b);
            }
            printf("\n");
        }
        c=0;
    }
    return 0;
}