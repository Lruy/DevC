#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

int n,m,timer;
int v[10005],dfn[10005],low[10005];
bool in_stk[10005];
vector<int> adj[10005];
stack<int> stk;
void tarjan(int u){
    dfn[u]=low[u]=++timer;
    stk.push(u);
    in_stk[u]=true;
    for(int v : adj[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(in_stk[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        int t1;
        do{
            t1=stk.top();
            stk.pop();
            in_stk[t1]=false;
            //canceled here
        }while(u!=t1);
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=0;i<m;i++){
        int t1,t2;
        cin>>t1>>t2;
        adj[t1].push_back(t2);
    }

    return 0;
}