#include <stdio.h>

int main() {
    int a,b,c,d,t,i;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(i=1;i<=3;i++) {
        if (a>b){
            t=b;
            b=a;
            a=t;
        }
        if (b>c) {
            t=c;
            c=b;
            b=t;
        }
        if (c>d) {
            t=d;
            d=c;
            c=t;
        }
    }
    printf("%d %d %d %d",a,b,c,d);
    return 0;
}