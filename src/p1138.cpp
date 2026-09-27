#include <iostream>
using namespace std;
typedef long long ll;

bool vis[30005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,k;
    cin>>n>>k;
    if(k<1){cout<<"NO RESULT";return 0;}
    for(int i=0;i<n;i++){ll tmp;cin>>tmp;vis[tmp]=true;}
    ll cnt=0;
    for(int i=1;i<=30000;i++){
        if(vis[i])cnt++;
        if(cnt==k){cout<<i;return 0;}
    }
    cout<<"NO RESULT";
    return 0;
}