#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD=998244353;
ll a[200005];
ll pre[200005];
ll mul[200005];
ll mull[200005];
void Exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) x = 1, y = 0;
    else Exgcd(b, a % b, y, x), y -= a / b * x;
}
bool cmp(ll& a,ll& b){return a>b;}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    mul[0]=mul[1]=1;
    for(int i=2;i<200005;i++){
        mul[i]=mul[i-1]*i%MOD;
    }
    for(int i=1;i<200005;i++){
        ll x,y;
        Exgcd(mul[i],MOD,x,y);
        mull[i]=x%MOD;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n,cmp);
        pre[0]=a[0];
        for(int i=1;i<n;i++){pre[i]=(pre[i-1]+a[i])%MOD;}
        for(int i=1;i<n;i++){
            ll tmp=(pre[i-1]-i*a[i])%MOD;
            ans+=((tmp*mul[n-1])%MOD*mull[i])%MOD;
            ans=(ans%MOD+MOD)%MOD;
        }
        cout<<ans<<'\n';
    }
    return 0;
}