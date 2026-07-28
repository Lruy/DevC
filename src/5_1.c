#include <stdio.h>

int main () {
    int i,j,n;
    int d=0;
    scanf("%d",&n);
    for (i=2;i<n;i++) {
        for (j=2,d=0;j<i;j++) {
            if (i%j==0)d=1;
        }
        if (d==0){
            if (i!=2) {
                printf(" %d",i);
            }
            else printf("%d",i);
        }
    }
        return 0;
}