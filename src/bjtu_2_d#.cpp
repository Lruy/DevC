#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

struct edge{
    int dom,len;
    edge(int a,int b){dom=a;len=b;}
};
int n,m;
vector<edge> v[100005];
bool vis[100005];
vector<int> sp(100005,1e9);
struct que{
    int pos,dist;
    que(int a,int b){pos=a;dist=b;}
    friend bool operator<(que a,que b){
        return a.dist>b.dist;
    }
};
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        v[t1].push_back(edge(t2,t3));
        v[t2].push_back(edge(t1,t3));
    }
    priority_queue<que> q;
    q.push(que(1,0));
    while(!q.empty()){
        if(vis[q.top().pos]){q.pop();continue;}
        sp[q.top().pos]=min(q.top().dist,sp[q.top().pos]);
        for(int i=0;i<v[q.top().pos].size();i++){
            if(!vis[v[q.top().pos][i].dom])q.push(que(v[q.top().pos][i].dom,q.top().dist+v[q.top().pos][i].len));
        }
        vis[q.top().pos]=true;
        q.pop();
    }
    for(int i=1;i<=n;i++){
        if(sp[i]!=1e9)cout<<sp[i]<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}