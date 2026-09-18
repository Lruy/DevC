#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;

bool fd;
ll n,m,s,t,ans;
struct Edge{
    ll from,to,val;
    ll rev;
    Edge(){}
    Edge(ll a,ll b,ll c,ll d):from(a),to(b),val(c),rev(d){}
};
vector<Edge> v[205];
vector<Edge> res[205];
vector<Edge> lvl[205];
ll lvll[205];
ll cur[205];
vector<pair<ll,ll> > vis;

void dfs(ll pos,ll cost){
    if(fd)return;
    if(pos==t){
        if(cost){
            ans+=cost;
            fd=true;
            for(auto p:vis){
                res[p.first][p.second].val-=cost;
                res[res[p.first][p.second].to][res[p.first][p.second].rev].val+=cost;
            }
        }
        return;
    }
    else{
        ll sz=res[pos].size();
        for(int i=cur[pos];i<sz;i++){
            Edge tmp=res[pos][i];
            if(tmp.val>0 && lvll[tmp.to]==lvll[pos]+1){
                cur[pos]=i+1;
                vis.push_back(make_pair(pos,i));
                dfs(tmp.to,min(cost,tmp.val));
                vis.pop_back();
            }
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    s=1;
    t=n;
    for(int i=0;i<m;i++){
        ll u,vv,w;
        cin>>u>>vv>>w;
        w*=1001;
        w++;
        ll t1=v[u].size();
        ll t2=v[vv].size();
        v[u].push_back(Edge(u,vv,w,t2));
        res[u].push_back(Edge(u,vv,w,t2));
        v[vv].push_back(Edge(vv,u,0,t1));
        res[vv].push_back(Edge(vv,u,0,t1));
    }
    ll lst=0;
    while(true){
        memset(lvll,0,sizeof(lvll));
        memset(cur,0,sizeof(cur));
        queue<pair<ll,ll> > q;
        q.push(make_pair(s,0));
        while(!q.empty()){
            pair<ll,ll> tmp=q.front();
            q.pop();
            if(tmp.first==t)continue;
            for(auto p:res[tmp.first]){
                if(p.to!=s && !lvll[p.to] && p.val>0){
                    lvll[p.to]=tmp.second+1;
                    q.push(make_pair(p.to,lvll[p.to]));
                }
            }
        }
        fd=true;
        while(fd){
            fd=false;
            dfs(s,1e18);
        }
        if(ans==lst)break;
        else lst=ans;
    }
    cout<<ans/1001<<" "<<ans%1001;
    return 0;
}