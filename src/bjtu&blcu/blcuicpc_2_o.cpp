#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;

ll n,m,cnt;
ll nexist[400005],k[400005],ans[400005];
bool vis[400005];
vector<vector<ll> > v(400005);
ll fa[400005];
ll find(ll a){
    if(fa[a]<0)return a;
    else return fa[a]=find(fa[a]);
}
void merge(ll a,ll b){
    ll roota=find(a);
    ll rootb=find(b);
    if(roota!=rootb){
        if(fa[roota]<fa[rootb]){
            fa[roota]+=fa[rootb];
            fa[rootb]=roota;
        }
        else{
            fa[rootb]+=fa[roota];
            fa[roota]=rootb;
        }
        cnt--;
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cnt=n;
    memset(fa,-1,sizeof(fa));
    for(int i=0;i<m;i++){
        ll t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    ll t3;
    cin>>t3;
    for(int i=0;i<t3;i++){
        cin>>k[i];
        nexist[k[i]]=1;
        cnt--;
    }
    queue<ll> q;
    for(ll i=0;i<n;i++){
        if(!nexist[i])q.push(i);
    }
    while(!q.empty()){
        ll tmp=q.front();
        q.pop();
        if(vis[tmp])continue;
        vis[tmp]=true;
        for(auto i:v[tmp]){
            if(!nexist[i] && !vis[i]){
                merge(tmp,i);
            }
        }
    }
    ll tmmp=cnt;
    for(int i=t3-1;i>=0;i--){
        nexist[k[i]]=0;
        cnt++;
        for(auto j:v[k[i]]){
            if(!nexist[j]){
                merge(k[i],j);
            }
        }
        ans[i]=cnt;
    }
    for(int i=0;i<t3;i++){
        cout<<ans[i]<<'\n';
    }
    cout<<tmmp<<'\n';
    return 0;
}