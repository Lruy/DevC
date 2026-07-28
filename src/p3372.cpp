#include <iostream>
using namespace std;
typedef long long ll;

ll n,m;
ll a[100005];
struct Node{
    ll sum,lazy;
}mp[400005];
inline void pushup(ll pos){
    mp[pos].sum=mp[pos<<1].sum+mp[pos<<1|1].sum;
}
void pushdown(ll pos,ll l,ll r){
    if(!mp[pos].lazy)return;
    ll mid=(l+r)>>1;
    ll val=mp[pos].lazy;
    mp[pos<<1].lazy+=val;
    mp[pos<<1].sum+=val*(mid-l+1);
    mp[pos<<1|1].lazy+=val;
    mp[pos<<1|1].sum+=val*(r-mid);
    mp[pos].lazy=0;
}
void build(ll pos,ll l,ll r){
    if(l==r){
        mp[pos].sum=a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
void update(ll pos,ll l,ll r,ll L,ll R,ll val){
    if(L<=l && r<=R){
        mp[pos].lazy+=val;
        mp[pos].sum+=(r-l+1)*val;
        return;
    }
    pushdown(pos,l,r);
    ll mid=(l+r)>>1;
    if(L<=mid)update(pos<<1,l,mid,L,R,val);
    if(R>mid)update(pos<<1|1,mid+1,r,L,R,val);
    pushup(pos);
}
ll query(ll pos,ll l,ll r,ll L,ll R){
    if(L<=l && r<=R)return mp[pos].sum;
    pushdown(pos,l,r);
    ll res=0;
    ll mid=(l+r)>>1;
    if(L<=mid)res+=query(pos<<1,l,mid,L,R);
    if(R>mid)res+=query(pos<<1|1,mid+1,r,L,R);
    return res;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(m--){
        ll t1;
        cin>>t1;
        if(t1==1){
            ll t2,t3,t4;
            cin>>t2>>t3>>t4;
            update(1,1,n,t2,t3,t4);
        }
        else{
            ll t2,t3;
            cin>>t2>>t3;
            cout<<query(1,1,n,t2,t3)<<'\n';
        }
    }
    return 0;
}