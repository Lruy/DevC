#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Node{
    ll lson,rson;
}tree[1000005];
ll rd[1000005];
ll n;
vector<ll> v;
ll dfs(ll pos){
    ll tmp=0;
    if(tree[pos].lson!=0)tmp=max(tmp,dfs(tree[pos].lson));
    if(tree[pos].rson!=0)tmp=max(tmp,dfs(tree[pos].rson));
    return tmp+1;
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll t1,t2;
        cin>>t1>>t2;
        tree[i].lson=t1;
        tree[i].rson=t2;
        rd[t1]++;
        rd[t2]++;
    }
    for(int i=1;i<=n;i++){
        if(rd[i]==0)v.push_back(i);
    }
    ll maxx=0;
    for(auto p:v){
        maxx=max(maxx,dfs(p));
    }
    cout<<maxx;
    return 0;
}