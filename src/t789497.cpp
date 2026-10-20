#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

struct Edge{
    ll from,val;
    Edge(){}
    Edge(ll a,ll b):from(a),val(b){}
};
vector<Edge> v[200005];
ll a[200005];
ll ds[200005];
bool popped[200005];
ll ans=0;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ll tmp;cin>>tmp;
        a[i]-=tmp;
    }
    for(int i=1;i<n;i++){
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        v[t2].push_back(Edge(t1,t3));
        v[t1].push_back(Edge(t2,t3));
        ds[t1]++;ds[t2]++;
    }
    queue<ll> q;
    for(int i=1;i<=n;i++){
        if(ds[i]==1)q.push(i);
    }
    while(!q.empty()){
        ll tmp=q.front();
        q.pop();
        popped[tmp]=true;
        for(auto p:v[tmp]){
            if(!popped[p.from]){
                ds[p.from]--;
                if(ds[p.from]==1)q.push(p.from);
                if(a[tmp]!=0)ans+=(abs(a[tmp])-1)/p.val+1;
                a[p.from]+=a[tmp];
            }
        }
    }
    cout<<ans;
    return 0;
}