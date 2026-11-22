#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef long long Elemtype;
const long long N=1e5;
struct Heap{
    Elemtype a[N];
    ll size;
    Heap(){size=0;}
};
bool siftdown(Heap& h,ll pos){
    ll sz=h.size;
    if(pos<1||pos>sz)return false;
    if((pos<<1|1)<=sz){
        if(h.a[pos]<=min(h.a[pos<<1],h.a[pos<<1|1]))return false;
        else{
            if(h.a[pos<<1]<h.a[pos<<1|1]){
                swap(h.a[pos],h.a[pos<<1]);
                siftdown(h,pos<<1);
            }
            else{
                swap(h.a[pos<<1|1],h.a[pos]);
                siftdown(h,pos<<1|1);
            }
        }
        return true;
    }
    else if(pos<<1<=sz){
        if(h.a[pos]<=h.a[pos<<1])return false;
        else{
            swap(h.a[pos],h.a[pos<<1]);
            siftdown(h,pos<<1);
        }
        return true;
    }
    return false;
}
void Creat(Heap& h,Elemtype arr[],ll sz){
    if(sz>N)return;
    h.size=sz;
    for(int i=1;i<=sz;i++){
        h.a[i]=arr[i-1];
    }
    for(int i=sz/2;i>=1;i--){
        siftdown(h,i);
    }
}
void Traverse(Heap& h){
    bool first=true;
    ll a=0,b=1;
    for(int i=1;i<=h.size;i++){
        if(!first&&a!=0)cout<<" ";
        first=false;
        cout<<h.a[i];
        a++;
        if(a>=b){a=0;b*=2;cout<<'\n';}
    }
    if(a!=0)cout<<'\n';
}
Elemtype Delet(Heap& h){
    swap(h.a[h.size],h.a[1]);
    h.size--;
    siftdown(h,1);
    return h.a[h.size+1];
}
void Inser(Heap& h,Elemtype e){
    h.size++;
    h.a[h.size]=e;
    bool flag=true;
    for(ll tmp=h.size>>1;tmp&&flag;tmp>>=1){
        flag=siftdown(h,tmp);
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    Heap h;
    ll a[]={12,84,44,88,59,95,51,47,40,88,61,67,58,42};
    Creat(h,a,sizeof(a)/sizeof(ll));
    Traverse(h);
    cout<<Delet(h)<<'\n';
    Traverse(h);
    Inser(h,1LL);
    Traverse(h);
    return 0;
}