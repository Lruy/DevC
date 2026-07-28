#include <stdio.h>

int main() {
    int i,j;
    int dx=0,xx=0,sz=0,kg=0,fk=0;
    char a[3][80];
    for (i=0;i<3;i++) {
        gets(a[i]);
        for (j=0;j<80 && a[i][j]!='\0';j++) {
            if (a[i][j]>='A' && a[i][j]<='Z')dx+=1;
            else if (a[i][j]>='a' && a[i][j]<='z')xx+=1;
            else if (a[i][j]>='0' && a[i][j]<='9')sz+=1;
            else if (a[i][j]==' ')kg+=1;
            else fk+=1;
        }
    }
    printf("%d %d %d %d %d",dx,xx,sz,kg,fk);
    return 0;
}