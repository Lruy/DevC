#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll a;
    cin>>a;
    if(a%400==0||(a%100!=0&&a%4==0))cout<<"Y";
    else cout<<"N";
    return 0;
}