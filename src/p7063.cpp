#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll cnt[54][2];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,ans=1e18;
    cin>>n;
    for(int i=1;i<1000000;i++){
        ll sum=0;ll tmp=i;
        while(tmp){sum+=tmp%10;tmp/=10;}
        if(cnt[sum][1]!=n){cnt[sum][0]+=i;cnt[sum][1]++;}
        else ans=min(ans,cnt[sum][0]);
    }
    cout<<ans;
    return 0;
}