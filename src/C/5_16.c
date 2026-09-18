#include <stdio.h>

int main() {
    int i,j,k;
    char b;
    char a[10][21];
    for(i=0;i<10;i++)gets(a[i]);
    for(i=0;i<10;i++) {
        for(j=0;j<9;j++) {
            if (a[j][0]>a[j+1][0]) {
                for (k=0;k<20;k++) {
                    b=a[j][k];
                    a[j][k]=a[j+1][k];
                    a[j+1][k]=b;
                }
            }
            else if (a[j][0]==a[j+1][0]) {
                if (a[j][1]>a[j+1][1]) {
                    for (k=0;k<20;k++) {
                        b=a[j][k];
                        a[j][k]=a[j+1][k];
                        a[j+1][k]=b;
                    }
                }
                else if (a[j][1]==a[j+1][1]) {
                    if (a[j][2]>a[j+1][2]) {
                        for (k=0;k<20;k++) {
                            b=a[j][k];
                            a[j][k]=a[j+1][k];
                            a[j+1][k]=b;
                        }
                    }
                    else if (a[j][2]==a[j+1][2]) {
                        if (a[j][3]>a[j+1][3]) {
                            for (k=0;k<20;k++) {
                                b=a[j][k];
                                a[j][k]=a[j+1][k];
                                a[j+1][k]=b;
                            }
                        }
                        else if (a[j][3]==a[j+1][3]) {
                            if (a[j][4]>a[j+1][4]) {
                                for (k=0;k<20;k++) {
                                    b=a[j][k];
                                    a[j][k]=a[j+1][k];
                                    a[j+1][k]=b;
                                }
                            }
                            else if (a[j][4]==a[j+1][4]) {
                                if (a[j][5]>a[j+1][5]) {
                                    for (k=0;k<20;k++) {
                                        b=a[j][k];
                                        a[j][k]=a[j+1][k];
                                        a[j+1][k]=b;
                                    }
                                }
                                else if (a[j][5]==a[j+1][5]) {
                                    if (a[j][6]>a[j+1][6]) {
                                        for (k=0;k<20;k++) {
                                            b=a[j][k];
                                            a[j][k]=a[j+1][k];
                                            a[j+1][k]=b;
                                        }
                                    }
                                    else if (a[j][6]==a[j+1][6]) {
                                        if (a[j][7]>a[j+1][7]) {
                                            for (k=0;k<20;k++) {
                                                b=a[j][k];
                                                a[j][k]=a[j+1][k];
                                                a[j+1][k]=b;
                                            }
                                        }
                                        else if (a[j][7]==a[j+1][7]) {
                                            if (a[j][8]>a[j+1][8]) {
                                                for (k=0;k<20;k++) {
                                                    b=a[j][k];
                                                    a[j][k]=a[j+1][k];
                                                    a[j+1][k]=b;
                                                }
                                            }
                                            else if (a[j][8]==a[j+1][8]) {
                                                if (a[j][9]>a[j+1][9]) {
                                                    for (k=0;k<20;k++) {
                                                        b=a[j][k];
                                                        a[j][k]=a[j+1][k];
                                                        a[j+1][k]=b;
                                                    }
                                                }
                                                else if (a[j][9]==a[j+1][9]) {
                                                    if (a[j][10]>a[j+1][10]) {
                                                        for (k=0;k<20;k++) {
                                                            b=a[j][k];
                                                            a[j][k]=a[j+1][k];
                                                            a[j+1][k]=b;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<10;i++) {
        puts(a[i]);
    }
    return 0;
}