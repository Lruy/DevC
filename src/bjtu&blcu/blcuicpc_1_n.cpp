#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m;
ll a[500005]={};
struct Node{
    ll maxx,maxl,maxr,sum;
}tr[2000005];
void pushup(Node &p,const Node &i,const Node &j){
    p.sum=i.sum+j.sum;
    p.maxl=max(i.maxl,i.sum+j.maxl);
    p.maxr=max(j.maxr,i.maxr+j.sum);
    p.maxx=max(max(max(max(p.maxl,p.maxr),i.maxx),j.maxx),i.maxr+j.maxl);
    return;
}
void build(ll pos,ll l,ll r){
    if(l>=r){
        ll tmp=a[l];
        tr[pos].sum=tmp;
        tr[pos].maxx=tmp;
        tr[pos].maxl=tmp;
        tr[pos].maxr=tmp;
        return;
    }
    ll mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(tr[pos],tr[pos<<1],tr[pos<<1|1]);
}
void update(ll tar,ll val,ll pos,ll l,ll r){
    if(l>=r){
        tr[pos].maxl=tr[pos].maxr=tr[pos].maxx=tr[pos].sum=val;
        return;
    }
    ll mid=(l+r)>>1;
    if(tar<=mid)update(tar,val,pos<<1,l,mid);
    else update(tar,val,pos<<1|1,mid+1,r);
    pushup(tr[pos],tr[pos<<1],tr[pos<<1|1]);
}
Node query(ll L,ll R,ll pos,ll l,ll r){
    if(L<=l && r<=R)return tr[pos];
    ll mid=(l+r)>>1;
    if(L<=mid && R>mid){
        Node res;
        pushup(res,query(L,R,pos<<1,l,mid),query(L,R,pos<<1|1,mid+1,r));
        return res;
    }
    else if(L<=mid)return query(L,R,pos<<1,l,mid);
    else return query(L,R,pos<<1|1,mid+1,r);
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(m--){
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        if(t1==1){
            if(t2>t3)swap(t2,t3);
            cout<<query(t2,t3,1,1,n).maxx<<'\n';
        }
        else update(t2,t3,1,1,n);
    }
    return 0;
}