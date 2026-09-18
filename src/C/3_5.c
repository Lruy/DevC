#include <stdio.h>

int main() {
    int x;
    scanf("%d",&x);
    if (x>9999) {
        printf("5\n");
        int a=x/10000;
        int b=x/1000-a*10;
        int c=x/100-a*100-b*10;
        int d=x/10-a*1000-b*100-c*10;
        int e=x-a*10000-b*1000-c*100-d*10;
        printf("%d %d %d %d %d\n",a,b,c,d,e);
        int f=a+b*10+c*100+d*1000+e*10000;
        printf("%d",f);
    }else if (x>999) {
        printf("4\n");
        int a=x/1000;
        int b=x/100-a*10;
        int c=x/10-a*100-b*10;
        int d=x-a*1000-b*100-c*10;
        printf("%d %d %d %d\n",a,b,c,d);
        int e=a+b*10+c*100+d*1000;
        printf("%d",e);
    }else if (x>99) {
        printf("3\n");
        int a=x/100;
        int b=x/10-a*10;
        int c=x-a*100-b*10;
        printf("%d %d %d\n",a,b,c);
        int d=a+b*10+c*100;
        printf("%d",d);
    }else if (x>9) {
        printf("2\n");
        int a=x/10;
        int b=x-a*10;
        printf("%d %d\n",a,b);
        int c=a+b*10;
        printf("%d",c);
    }else {
        printf("1\n");
        printf("%d\n",x);
        printf("%d",x);
    }
    return 0;
}