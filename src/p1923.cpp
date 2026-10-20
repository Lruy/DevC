#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[5000005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    cout<<a[k];
    return 0;
}