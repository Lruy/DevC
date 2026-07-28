#include <stdio.h>

int calcGCG(int a,int b) {
    int c;
    if(a>b) {
        c=a;
        a=b;
        b=c;
    }
    while(b%a!=0) {
        c=b%a;
        b=a;
        a=c;
    }
    return a;
}

int calcLCM(int a,int b) {
    return(a*b/calcGCG(a,b));
}

int main() {
    int x,y;
    int calcGCG(int a,int b);
    int calcLCM(int a,int b);
    scanf("%d %d",&x,&y);
    printf("%d %d",calcGCG(x,y),calcLCM(x,y));
}