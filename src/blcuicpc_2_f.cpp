#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n,m,s;
vector<vector<ll> > v;
ll fat[500005][20];
ll dep[500005];
void dfs(ll pos,ll fa,ll de){
    dep[pos]=de;
    fat[pos][0]=fa;
    for(ll i=1;1LL<<i<=de;i++){
        fat[pos][i]=fat[fat[pos][i-1]][i-1];
    }
    for(auto i:v[pos]){
        if(i!=fa){
            dfs(i,pos,de+1);
        }
    }
}
ll lca(ll a,ll b){
    if(dep[a]<dep[b])swap(a,b);
    for(ll i=19;i>=0;i--){
        if(dep[a]-(1LL<<i)>=dep[b]){
            a=fat[a][i];
        }
    }
    if(a==b)return a;
    for(ll i=19;i>=0;i--){
        if(fat[a][i]!=fat[b][i]){
            a=fat[a][i];
            b=fat[b][i];
        }
    }
    return fat[a][0];
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    v.resize(n+1);
    for(ll i=1;i<n;i++){
        ll t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(s,-1,1);
    while(m--){
        ll t1,t2;
        cin>>t1>>t2;
        cout<<lca(t1,t2)<<'\n';
    }
    return 0;
}