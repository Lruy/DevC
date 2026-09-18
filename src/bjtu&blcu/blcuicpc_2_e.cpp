#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

ll n,m;
ll fat[5005];
struct Edge{
    ll from,to,val;
    Edge(ll a,ll b,ll c){
        from=a;to=b;val=c;
    }
    bool operator>(const Edge& other)const{
        return val>other.val;
    }
    bool operator<(const Edge& other)const{
        return val<other.val;
    }
};
priority_queue<Edge,vector<Edge>,greater<Edge> > q;
ll find(ll a){
    if(fat[a]<0)return a;
    else return fat[a]=find(fat[a]);
}
void merge(ll a,ll b){
    ll roota=find(a);
    ll rootb=find(b);
    if(roota!=rootb){
        if(fat[roota]<fat[rootb]){fat[roota]+=fat[rootb];fat[rootb]=roota;}
        else{fat[rootb]+=fat[roota];fat[roota]=rootb;}
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(fat,-1,sizeof(fat));
    while(m--){
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        q.push(Edge(t1,t2,t3));
    }
    ll cnt=0,ans=0;
    while(cnt<n-1){
        if(q.empty()){
            cout<<"orz";
            return 0;
        }
        ll x=q.top().from;
        ll y=q.top().to;
        if(find(x)!=find(y)){
            merge(x,y);
            cnt++;
            ans+=q.top().val;
            q.pop();
        }
        else q.pop();
    }
    cout<<ans;
    return 0;
}