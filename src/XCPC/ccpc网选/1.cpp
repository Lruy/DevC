#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll t;

signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        ll h=(s[0]-'0')*10+(s[1]-'0');
        ll mm=(s[3]-'0')*10+(s[4]-'0');
        double tmp=1.0*m/n;
        if(m>=50||tmp>=0.2||h>=4)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}