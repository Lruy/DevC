#include <stdio.h>

int main() {
    int n,i,count=0;
    scanf("%d",&n);
    int a[n];
    int *p=a;
    for (i=0;i<n;i++,p++) {
        *p=i+1;
    }
    p=a;
    int nn=n;
    while (n!=1) {
        if (*p!=0) {
            count++;
            if (count==3) {
                *p=0;
                count=0;
                n--;
            }
        }
        p++;
        if (p==a+nn) {
            p=a;
        }
    }
    p=a;
    while (*p==0) p++;
    printf("%d",*p);
}