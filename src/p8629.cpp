#include <iostream>
using namespace std;

double power(int x,int y){
    double temp=1;
    while(y--)temp*=x;
    return temp;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin>>n;
    double s;
    cin>>s;
    cout<<((s-n-1)/(power(2,n+1)-1))+1;
    return 0;
}