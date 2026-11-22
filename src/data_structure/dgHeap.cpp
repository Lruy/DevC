#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long long Elemtype;
const long long N = 1e5;
struct Heap{
    Elemtype a[N];
    ll size;
    Heap(){size=0;}
};
ll pow(ll a,ll b){
    ll tmp=a,sum=1;
    while(b){
        if(b&1)sum*=tmp;
        tmp*=tmp;
        b>>=1;
    }
    return sum;
}
void Traverse(Heap& h){
    ll a=0,b=1;
    ll lvl=1;
    ll tmp=h.size;
    while(tmp>>=1)lvl++;
    for(int i=1;i<=h.size;i++){
        if(a==0)for(int i=0;i<pow(2,lvl)-1;i++)cout<<" ";
        else for(int i=0;i<pow(2,lvl+1)-2;i++)cout<<" ";
        cout<<h.a[i];
        a++;
        if(a>=b){a=0;b*=2;cout<<'\n';lvl--;}
    }
    if(a!=0)cout<<'\n';
}
void build(Heap& h,ll pos,ll arr[],ll sz){
    if(pos<1||pos>sz)return;
    if(pos==1)h.size=sz;
    h.a[pos]=arr[pos-1];
    build(h,pos<<1,arr,sz);
    build(h,pos<<1|1,arr,sz);
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll a[]={12,84,44,88,59,95,51,47,40,88,61,67,58,42};
    sort(a,a+sizeof(a)/sizeof(ll));
    Heap h;
    build(h,1,a,sizeof(a)/sizeof(long long));
    Traverse(h);
    return 0;
}