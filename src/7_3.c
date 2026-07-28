#include <stdio.h>
#define N 10
void input(int *number)
{
    int i;
    for (i=0;i<N;i++) {
        scanf("%d",&number[i]);
    }
}
void swap(int *number)
{
    int temp,num=0,i;
    temp=number[0];
    for (i=1;i<N;i++) {
        if (temp>number[i]) {
            num=i;
            temp=number[i];
        }
    }
    if (num!=0) {
        number[num]=number[0];
        number[0]=temp;
    }
    temp=number[0];
    num=0;
    for (i=1;i<N;i++) {
        if (temp<number[i]) {
            num=i;
            temp=number[i];
        }
    }
    if (num!=0) {
        number[num]=number[N-1];
        number[N-1]=temp;
    }
}
void output(int *number)
{
    int i;
    for (i=0;i<10;i++) {
        printf("%d ",number[i]);
    }
}
int main()
{
    int number[N];
    input(number);
    swap(number);
    output(number);
    return 0;
}