#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int> > mp(100005);
int dist[100005];
struct trail{
    int pos,len;
    trail(int x,int y){
        pos=x;len=y;
    }
};
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=2;i<=n;i++){
        dist[i]=-1;
    }
    queue<trail> q;
    q.push(trail(1,0));
    while(!q.empty()){
        if(dist[q.front().pos]==-1)dist[q.front().pos]=q.front().len;
        for(int i=0;i<mp[q.front().pos].size();i++){
            if(dist[mp[q.front().pos][i]]==-1){
                q.push(trail(mp[q.front().pos][i],q.front().len+1));
            }
        }
        q.pop();
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<'\n';
    }
    return 0;
}