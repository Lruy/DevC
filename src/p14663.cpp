#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<(ll)(sqrt(n)/3)<<'\n';
    }
    return 0;
}