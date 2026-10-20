#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    while(n--){ll tmp;cin>>tmp;ans^=tmp;}
    cout<<ans;
    return 0;
}