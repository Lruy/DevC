#include <stdio.h>
#include <math.h>

void root1(float a,float b,float c) {
    printf("%.2f",(-b+sqrt(b*b-4*a*c))/(2*a));
}

void root2(float a,float b,float c) {
    printf("%.2f %.2f",(-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
}

void root3(float a,float b,float c) {
    printf("%.2f+%.2fi %.2f-%.2fi",-b/(2*a),sqrt(4*a*c-b*b)/(2*a),-b/(2*a),sqrt(4*a*c-b*b)/(2*a));
}

int main() {
    float x,y,z;
    void root1(float,float,float);
    void root2(float,float,float);
    void root3(float,float,float);
    scanf("%f %f %f",&x,&y,&z);
    float delta=y*y-4*x*z;
    if(delta>0)root2(x,y,z);
    else if (delta==0)root1(x,y,z);
    else root3(x,y,z);
    return 0;
}