#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[2000005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>a[i];
    sort(a,a+m);
    for(int i=0;i<m;i++){if(i)cout<<" ";cout<<a[i];}
    return 0;
}