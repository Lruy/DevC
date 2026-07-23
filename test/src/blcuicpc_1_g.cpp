#include <iostream>
using namespace std;
typedef long long ll;

ll n,ans;
ll mp[500005],tmp[500005];
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
    for(ll p=1;p<=n;p++){
        cin>>mp[p];
    }
    mergesort(1,n);
    cout<<ans;
    return 0;
}