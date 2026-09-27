#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[10005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }
    ll tmp=pow(2,n);
    for(int i=0;i<tmp;i++)cin>>a[i];
    tmp/=2;
    ll lmax=0,rmax=tmp;
    for(int i=1;i<tmp;i++){
        if(a[lmax]<a[i])lmax=i;
    }
    for(int i=1;i<tmp;i++){
        if(a[rmax]<a[tmp+i])rmax=tmp+i;
    }
    if(a[rmax]>a[lmax])cout<<lmax+1;
    else cout<<rmax+1;
    return 0;
}