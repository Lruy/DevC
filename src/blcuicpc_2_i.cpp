#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll n,ans=1e15;
ll f[105],w[105],sz[105];
vector<vector<ll> > v(105);
void dfs(ll pos,ll fa,ll dep){
    sz[pos]=w[pos];
    for(auto p:v[pos]){
        if(p==fa)continue;
        dfs(p,pos,dep+1);
        sz[pos]+=sz[p];
    }
    f[1]+=w[pos]*dep;
}
void dfs2(ll pos,ll fa){
    ans=min(ans,f[pos]);
    for(auto p:v[pos]){
        if(p==fa)continue;
        f[p]=f[pos]+sz[1]-2*sz[p];
        dfs2(p,pos);
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll u,p;
        cin>>w[i]>>u>>p;
        if(p!=0){
            v[i].push_back(p);
            v[p].push_back(i);
        }
        if(u!=0){
            v[i].push_back(u);
            v[u].push_back(i);
        }
    }
    dfs(1,-1,0);
    dfs2(1,-1);
    cout<<ans;
    return 0;
}