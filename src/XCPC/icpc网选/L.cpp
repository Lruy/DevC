#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t;
ll a[100005];
ll lsum[100005];
ll rsum[100005];
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        ll n;
        ll ans=1e17;
        cin>>n;
        cin>>a[0];
        rsum[0]=a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            rsum[i]=rsum[i-1]+a[i];
        }
        lsum[0]=a[0];
        for(int i=1;i<n;i++){
            lsum[i]=lsum[i-1]+a[n-i];
        }
        for(int i=0;i<n;i++){
            ll tmp=rsum[i]*2-a[i];
            tmp+=(n-1-i)*(a[i]+a[i+1]);
            ans=min(tmp,ans);
        }
        for(int i=0;i<n;i++){
            ll tmp=lsum[i]*2-a[(n-i)%n];
            tmp+=(n-1-i)*(a[(n-i)%n]+a[n-i-1]);
            ans=min(tmp,ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}