#include <stdio.h>

int main() {
    int m,n;
    double b=0;
    scanf("%d",&m);
    for(;m!=1;m--) {
        double a=1;
        for(n=m;n!=1;n--) {
            a=a*n;
        }
        b=b+a;
    }
    printf("%.5e\n",b);
    return 0;
}