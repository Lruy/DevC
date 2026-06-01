#include <stdio.h>

int main() {
    int m,n,a;
    scanf("%d %d",&m,&n);
    if (m>n) {
        int temp=m;
        m=n;
        n=temp;
    }
    int x=m;
    int y=n;
    for (a=1;a!=0;) {
        a=n%m;
        n=m;
        m=a;
    }
    printf("%d %d",n,x*y/n);
    return 0;
}