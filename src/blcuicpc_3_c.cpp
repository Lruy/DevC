#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

ll n,m,timer,scccnt;
ll w[10005];
ll sccid[10005],sccval[10005],dfn[10005],low[10005];
bool instk[10005];
struct Edge{
    ll from,to;
    bool ru;
    Edge(){}
    Edge(ll a,ll b,bool c):from(a),to(b),ru(c){}
};
vector<vector<Edge> > v(10005);
vector<vector<Edge> > scc(10005);
stack<ll> stk;
void tarjan(ll u){
    timer++;
    dfn[u]=timer;
    low[u]=timer;
    stk.push(u);
    instk[u]=true;
    for(auto p:v[u]){
        if(!p.ru){
            if(!dfn[p.to]){
                tarjan(p.to);
                low[u]=min(low[p.to],low[u]);
            }
            else if(instk[p.to]){
                low[u]=min(low[u],dfn[p.to]);
            }
        }
    }
    if(dfn[u]==low[u]){
        scccnt++;
        ll tmp;
        do{
            tmp=stk.top();
            stk.pop();
            sccid[tmp]=scccnt;
            sccval[scccnt]+=w[tmp];
            instk[tmp]=false;
        }while(tmp!=u);
    }
}
ll rd[10005];
ll dp[10005];
ll ans;
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=0;i<m;i++){
        ll t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(Edge(t1,t2,false));
        v[t2].push_back(Edge(t1,t2,true));
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        ll t1=sccid[i];
        for(auto p:v[i]){
            if(!p.ru){
                ll t2=sccid[p.to];
                if(t1!=t2){
                    scc[t1].push_back(Edge(t1,t2,false));
                    rd[t2]++;
                }
            }
            else{
                ll t2=sccid[p.from];
                if(t1!=t2)scc[t1].push_back(Edge(t2,t1,true));
            }
        }
    }
    queue<ll> q;
    for(int i=1;i<=scccnt;i++){
        if(rd[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll tmp=q.front();
        q.pop();
        dp[tmp]=max(dp[tmp],sccval[tmp]);
        for(auto p:scc[tmp]){
            if(p.ru){
                dp[tmp]=max(dp[tmp],sccval[tmp]+dp[p.from]);
            }
            else{
                rd[p.to]--;
                if(rd[p.to]==0){
                    q.push(p.to);
                }
            }
        }
        ans=max(ans,dp[tmp]);
    }
    cout<<ans;
    return 0;
}