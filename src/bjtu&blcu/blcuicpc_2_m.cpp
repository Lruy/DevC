#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,m;
ll fat[40005];
struct Edge{
    ll a,b,val;
    Edge(){}
    Edge(ll x,ll y,ll z):a(x),b(y),val(z){}
}eg[100005];
bool cmp(const Edge& a,const Edge& b){
    return a.val>b.val;
}
ll find(ll a){
    if(fat[a]<0)return a;
    else return fat[a]=find(fat[a]);
}
void merge(ll a,ll b){
    ll roota=find(a);
    ll rootb=find(b);
    if(roota!=rootb){
        if(fat[roota]<fat[rootb]){fat[roota]+=fat[rootb];fat[rootb]=roota;}
        else {fat[rootb]+=fat[roota];fat[roota]=rootb;}
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(fat,-1,sizeof(fat));
    for(int i=1;i<=m;i++){
        cin>>eg[i].a>>eg[i].b>>eg[i].val;
    }
    sort(eg+1,eg+m+1,cmp);
    for(int i=1;i<=m;i++){
        ll tmpa=eg[i].a,tmpb=eg[i].b,tmpv=eg[i].val;
        merge(tmpa,tmpb+n);
        merge(tmpb,tmpa+n);
        if(find(tmpa)==find(tmpa+n) || find(tmpb)==find(tmpb+n)){
            cout<<tmpv;
            return 0;
        }
    }
    cout<<0;
    return 0;
}