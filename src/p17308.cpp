#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    double a=0.0,b=0.0;
    for(int i=0;i<n;i++){double tmp;cin>>tmp;b+=tmp;}
    for(int i=0;i<n;i++){double tmp;cin>>tmp;a+=tmp;}
    cout<<a/b;
    return 0;
}