#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef double db;

struct Node{
    db sum,ssum,lazy;
}tr[400005];
ll n,m;
db a[100005];
inline void pushup(ll pos){
    tr[pos].sum=tr[pos<<1].sum+tr[pos<<1|1].sum;
    tr[pos].ssum=tr[pos<<1].ssum+tr[pos<<1|1].ssum;
    return;
}
void build(ll pos,ll l,ll r){
    if(l>=r){
        tr[pos].sum=a[l];
        tr[pos].ssum=a[l]*a[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
void pushdown(ll pos,ll l,ll r){
    if(!tr[pos].lazy)return;
    ll mid=(l+r)>>1;
    tr[pos<<1].lazy+=tr[pos].lazy;
    tr[pos<<1|1].lazy+=tr[pos].lazy;
    tr[pos<<1].ssum+=tr[pos].lazy*tr[pos].lazy*(mid-l+1)+2*tr[pos].lazy*tr[pos<<1].sum;
    tr[pos<<1].sum+=tr[pos].lazy*(mid-l+1);
    tr[pos<<1|1].ssum+=tr[pos].lazy*tr[pos].lazy*(r-mid)+2*tr[pos].lazy*tr[pos<<1|1].sum;
    tr[pos<<1|1].sum+=tr[pos].lazy*(r-mid);
    tr[pos].lazy=0;
}
db querya(ll pos,ll l,ll r,ll L,ll R){
    if(L<=l && r<=R)return tr[pos].sum;
    pushdown(pos,l,r);
    ll mid=(l+r)>>1;
    db ans=0;
    if(L<=mid)ans+=querya(pos<<1,l,mid,L,R);
    if(mid<R)ans+=querya(pos<<1|1,mid+1,r,L,R);
    return ans;
}
db queryb(ll pos,ll l,ll r,ll L,ll R){
    if(L<=l && r<=R)return tr[pos].ssum;
    pushdown(pos,l,r);
    ll mid=(l+r)>>1;
    db ans=0;
    if(L<=mid)ans+=queryb(pos<<1,l,mid,L,R);
    if(mid<R)ans+=queryb(pos<<1|1,mid+1,r,L,R);
    return ans;
}
void update(ll pos,ll l,ll r,ll L,ll R,db val){
    if(L<=l && r<=R){
        tr[pos].ssum+=2*tr[pos].sum*val+(r-l+1)*val*val;
        tr[pos].sum+=(r-l+1)*val;
        tr[pos].lazy+=val;
        return;
    }
    pushdown(pos,l,r);
    ll mid=(l+r)>>1;
    if(L<=mid)update(pos<<1,l,mid,L,R,val);
    if(mid<R)update(pos<<1|1,mid+1,r,L,R,val);
    pushup(pos);
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
            ll t2,t3;
            db t4;
            cin>>t2>>t3>>t4;
            update(1,1,n,t2,t3,t4);
        }
        else if(t1==2){
            ll t2,t3;
            cin>>t2>>t3;
            printf("%.4f\n",querya(1,1,n,t2,t3)/(t3-t2+1));
        }
        else{
            ll t2,t3;
            cin>>t2>>t3;
            db avg=querya(1,1,n,t2,t3)/(t3-t2+1);
            db ans=queryb(1,1,n,t2,t3)/(t3-t2+1)-avg*avg;
            printf("%.4f\n",ans);
        }
    }
    return 0;
}