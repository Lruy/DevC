#include <stdio.h>

int main(){
    int n,j,i;
    scanf("%d",&n);
    int p[n];
    for (i=2;i<n;i++){
        p[i] = 1;
    }
    for (i=2;i<n;i++){
        if(p[i]==1){
            for (j=i*2;j<n;j+=i) {
                p[j] = 0;
            }
        }
    }
    printf("2");
    for (i=3;i<n;i++) {
        if (p[i]==1)printf(" %d", i);
    }
    return 0;
}