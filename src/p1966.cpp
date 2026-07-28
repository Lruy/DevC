#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct match{
    ll height,num;
}a[100005],b[100005];
bool cmp(match& a,match &b){
    return a.height<b.height;
}
ll n,ans;
ll mp[100005],tmp[100005];
void mergesort(ll l,ll r){
    if(l>=r)return;
    ll mid=(l+r)>>1;
    mergesort(l,mid);
    mergesort(mid+1,r);
    ll i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(mp[i]<=mp[j]){
            tmp[k++]=mp[i++];
        }
        else{
            tmp[k++]=mp[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid)tmp[k++]=mp[i++];
    while(j<=r)tmp[k++]=mp[j++];
    for(int a=l;a<=r;a++){mp[a]=tmp[a];}
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].height;
        a[i].num=i;
    }
    for(int i=0;i<n;i++){
        cin>>b[i].height;
        b[i].num=i;
    }
    sort(a,a+n,cmp);
    sort(b,b+n,cmp);
    for(int i=0;i<n;i++){
        mp[b[i].num]=a[i].num;
    }
    mergesort(0,n-1);
    cout<<ans%99999997;
    return 0;
}