#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

ll n,m;
ll dist[200005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    fill(dist,dist+200005,-1);
    queue<ll> q;
    q.push(n);
    dist[n]=0;
    while(!q.empty()){
        ll x=q.front();q.pop();
        if(x==m){
            cout<<dist[x];
            return 0;
        }
        ll nx=x-1;
        if(nx>=0 && dist[nx]==-1){
            dist[nx]=dist[x]+1;
            q.push(nx);
        }
        nx=x+1;
        if(nx<=200000 && dist[nx]==-1){
            dist[nx]=dist[x]+1;
            q.push(nx);
        }
        nx=x<<1;
        if(nx<=200000 && dist[nx]==-1){
            dist[nx]=dist[x]+1;
            q.push(nx);
        }
    }
    return 0;
}
