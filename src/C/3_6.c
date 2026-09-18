#include <stdio.h>

int main() {
    int i;
    double b;
    scanf("%d",&i);
    int q=(i-1)/ 100000;
    switch (q) {
        case 0: b=i*0.1; break;
        case 1: b=10000+0.075*(i-100000); break;
        case 2:
        case 3: b=17500+0.05*(i-200000); break;
        case 4:
        case 5: b=27500+0.03*(i-400000); break;
        case 6:
        case 7:
        case 8:
        case 9: b=33500+0.015*(i-600000); break;
        default: b=39500+0.01*(i-1000000);
    }
    printf("%.2f",b);
    return 0;
}