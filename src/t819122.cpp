#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t1,t2;cin>>t1>>t2;
    double tmp=1.0*t1/3.0+1.0*t2/4.0;
    ll ans=tmp;
    if(fabs(tmp-ans)<0.000001);
    else ans++;
    cout<<ans;
    return 0;
}