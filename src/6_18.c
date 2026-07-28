#include <stdio.h>

int dayofyear(int y,int m,int d) {
    int ddmm[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (y%4==0 && y%100!=0 || y%400==0)ddmm[1]=29;
    int sum=0;
    int i;
    for(i=0;i<m-1;i++) {
        sum+=ddmm[i];
    }
    return sum+d;
}

int main() {
    int y,m,d;
    scanf("%d %d %d",&y,&m,&d);
    printf("%d\n",dayofyear(y,m,d));
    return 0;
}