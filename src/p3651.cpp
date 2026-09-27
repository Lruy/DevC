#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll sum=0;
    for(int i=1;i<=n;i++){
        ll tmp;
        cin>>tmp;
        sum+=tmp;
        if(i==k)sum-=2*tmp;
    }
    cout<<sum;
    return 0;
}