#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

ll t;
ll a[50005];
map<ll,ll> mp;
ll mex[100005];
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        mp.clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
            mex[i]=0;
        }
        for(int i=0;i<=n;i++){
            if(mp[i]!=0)continue;
            else{
                mex[0]=i;
                break;
            }
        }
        
        //for(ll i=0;i<=2*n;i++) cout<<mex[i]<<' ';
        //cout<<'\n';
        ll q,ans=0;
        cin>>q;
        while(q--){
            ll k;
            cin>>k;
            if(k>=2*n){
                ans^=mex[0];
                //cout<<mex[0]<<' ';
            }
            else{
                ans^=mex[k];
                //cout<<mex[k]<<' ';
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}