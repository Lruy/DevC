#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[100005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){if(i)cout<<" ";cout<<a[i];}
    return 0;
}