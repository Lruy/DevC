#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

struct edge{
    int from,to,len;
    edge(int a,int b,int c){from=a;to=b;len=c;}
};
struct lv{
    int from,to,len,level,flow;
    lv(int a,int b,int c,int d,int e=0){from=a;to=b;len=c;level=d;flow=e;}
    lv(edge a,int b,int c=0){from=a.from;to=a.to;len=a.len;level=b;flow=c;}
};
int n,m;
vector<vector<edge> > mp(405),res(405),lev(405);
int dfs(int pos,int rate){
    if(pos==n)return rate;
    int total=0;
    for(int k=0;k<lev[pos].size();k++){
        
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back(edge(a,b,c));
        mp[b].push_back(edge(b,a,0));
        res[a].push_back(edge(a,b,c));
        res[b].push_back(edge(b,a,0));
    }

    vector<int> level(n+5,-1);
    queue<lv> q;
    for(int i=0;i<mp[1].size();i++){
        q.push(lv(mp[1][i],1));
    }
    while(!q.empty()){
        level[q.front().to]=q.front().level;
        lev[q.front().from].push_back(edge(q.front().from,q.front().to,q.front().len));
        for(int i=0;i<res[q.front().to].size();i++){
            if(level[res[q.front().to][i].to]==-1){
                q.push(lv(res[q.front().to][i],q.front().level+1));
                level[res[q.front().to][i].to]=q.front().level+1;
            }
        }
        q.pop();
    }
    
    return 0;
}