#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b){a=a^b;b=a^b;a=a^b;}
    if(b>c){b=b^c;c=b^c;b=b^c;}
    if(a>b){a=a^b;b=a^b;a=a^b;}
    getchar();
    char t1,t2,t3;
    scanf("%c %c %c",&t1,&t2,&t3);
    if(t1=='A')printf("%d ",a);
    else if(t1=='B')printf("%d ",b);
    else if(t1=='C')printf("%d ",c);
    if(t2=='A')printf("%d ",a);
    else if(t2=='B')printf("%d ",b);
    else if(t2=='C')printf("%d ",c);
    if(t3=='A')printf("%d",a);
    else if(t3=='B')printf("%d",b);
    else if(t3=='C')printf("%d",c);
}