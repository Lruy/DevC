#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m;
bool afind=false;
int mp[10];
struct mod{
    int x,y,z;
    mod(int a,int b,int c){
        x=a;y=b;z=c;
    }
};
vector<mod> v;
struct bfs{
    int m[10];
    int len;
    bfs(int a[],int b){
        for(int i=0;i<10;i++)m[i]=a[i];
        len=b;
    }
};
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>mp[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(mod(a,b,c));
    }
    queue<bfs> q;
    q.push(bfs(mp,0));
    while(!q.empty()){
        bool goal=true;
        for(int i=0;i<10;i++){
            if(q.front().m[i]!=1)goal=false;
        }
        if(goal){
            cout<<q.front().len<<'\n';
            return 0;
        }
        for(int i=0;i<m;i++){
            q.front().m[v[i].x]^=1;
            q.front().m[v[i].y]^=1;
            q.front().m[v[i].z]^=1;
            q.push(bfs(q.front().m,q.front().len+1));
            q.front().m[v[i].x]^=1;
            q.front().m[v[i].y]^=1;
            q.front().m[v[i].z]^=1;
        }
        q.pop();
    }
    cout<<"-1";
    return 0;
}