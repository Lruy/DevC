#include <stdio.h>

int main(){
    int k,a=0,b=0,sum=0;
    scanf("%d",&k);
    while(k--){
        if(a==b){a=0;b++;}
        sum+=b;
        a++;
    }
    printf("%d",sum);
}