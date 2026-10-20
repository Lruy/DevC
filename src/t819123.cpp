#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll l,r,lim;
    cin>>l>>r>>lim;
    ll ans=0;
    for(int i=l;i<=r;i++)ans+=i/lim;
    cout<<ans;
    return 0;
}