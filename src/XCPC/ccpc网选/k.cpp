#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
ll n,m,t,in[200005],dis[200005];
vector<pair<ll,ll> > v[200005];
string s;
queue<ll> q;
struct node{
    vector<ll> rd;
    ll mi;
    ll minum;
}nds[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t;
    for(int i=0;i<n;i++){
        nds[i].mi=nds[i].minum=0;
        dis[i]=1e18;
    }
    dis[t]=0;
    cin>>s;
    ll a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        v[b].push_back({a,w});
        in[a]++;
    }
    q.push(t);
    while(!q.empty()){
        ll k=q.front();
        q.pop();
        for(auto i:v[k]){
            if(dis[i.first]>dis[k]){
                
            }
        }
    }
}
