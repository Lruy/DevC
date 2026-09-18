#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m;
unordered_map<ll,ll> memo;

ll f(ll x){
    if(x<=n)return n-x;
    if(memo.count(x))return memo[x];
    ll ans=x-n;
    if(!(x&1))ans=min(ans,1+f(x>>1));
    else{
        ans=min(ans,2+f((x-1)>>1));
        if(x>1)ans=min(ans,2+f((x+1)>>1));
    }
    return memo[x]=ans;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cout<<f(m);
    return 0;
}
