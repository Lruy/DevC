#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll a[200005];
ll pre[200005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        cin>>a[0];
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        ll cnt=0;
        vector<ll> v[200005];
        cout<<cnt<<'\n';
    }
    return 0;
}