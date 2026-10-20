#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll h,m;
        cin>>h>>m;
        if(m>=60){
            h+=m/60;
            m%=60;
        }
        if(h>=24)h%=24;
        cout<<h<<" "<<  m<<'\n';
    }
    return 0;
}