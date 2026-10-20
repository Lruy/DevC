#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,m,a;
    cin>>n>>m>>a;
    cout<<((n-1)/a+1)*((m-1)/a+1);
    return 0;
}