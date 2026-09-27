#include <iostream>
using namespace std;
typedef long long ll;

bool vis[200005];
ll a[200005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll cnt=n;
        for(int i=0;i<=n;i++)vis[i]=false;
        for(int i=0;i<m;i++){
            cin>>a[i];
            if(!vis[a[i]]){cnt--;vis[a[i]]=true;}
        }
        if(cnt){cout<<-1<<'\n';continue;}
        ll idx=1;
    }
    return 0;
}