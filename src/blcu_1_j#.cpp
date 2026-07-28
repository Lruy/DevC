#include <iostream>
using namespace std;

int n;
int main() {
    double ans=0;
    cin>>n;
    while(n--){
        double tmp;
        cin>>tmp;
        ans+=100/tmp-1;
    }
    printf("%.6lf",ans*20);
    return 0;
}