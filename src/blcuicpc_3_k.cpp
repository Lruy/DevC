#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Edge{
    ll from,to,val;
    Edge(){}
    Edge(ll a,ll b,ll c):from(a),to(b),val(c){}
};
ll c[105];
ll ind[105];
ll oud[105];
ll n,m;
vector<Edge> v[105];
vector<ll> ans;
bool vis[105];
bool nul=true;
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    queue<ll> q;
    for(int i=1;i<=n;i++){
        ll t1,t2;
        cin>>t1>>t2;
        if(t1){
            q.push(i);
            c[i]=t1;
        }
        else{
            c[i]-=t2;
        }
    }
    
    for(int i=0;i<m;i++){
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        v[t1].push_back(Edge(t1,t2,t3));
        ind[t2]++;
        oud[t1]++;
    }
    while(!q.empty()){
        ll tmp=q.front();
        q.pop();
        for(auto p:v[tmp]){
            ind[p.to]--;
            if(c[tmp]>0)c[p.to]+=c[tmp]*p.val;
            if(ind[p.to]==0)q.push(p.to);
        }
    }
    for(int i=1;i<=n;i++){
        if(oud[i]==0)ans.push_back(i);
    }
    for(auto p:ans){
        if(c[p]>0){
            nul=false;
            break;
        }
    }
    if(nul)cout<<"NULL";
    else{
        for(auto p:ans){
            if(c[p]>0)cout<<p<<" "<<c[p]<<'\n';
        }
    }
    return 0;
}