#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct edge{
    int dem,wei;
    edge(int x,int y){
        dem=x;wei=y;
    }
};
int n,m;
vector<vector<edge> > mp(100005);
int dist[100005];
int vis[100005];
struct trail{
    int pos,len;
    trail(int x,int y){
        pos=x;len=y;
    }
};
void dfs(int pos,int len){
    if(dist[pos]==-1)dist[pos]=len;
    else dist[pos]=min(dist[pos],len);
    for(int i=0;i<mp[pos].size();i++){
        if(vis[mp[pos][i].dem]==0){
            vis[mp[pos][i].dem]=1;
            dfs(mp[pos][i].dem,len+mp[pos][i].wei);
            vis[mp[pos][i].dem]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back(edge(b,c));
        mp[b].push_back(edge(a,c));
    }
    for(int i=2;i<=n;i++){
        dist[i]=-1;
    }
    vis[1]=1;vis[0]=1;
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<'\n';
    }
    return 0;
}