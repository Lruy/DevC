#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a<=b)cout<<"-1\n";
        else{
            cout<<min(a-b,b)<<'\n';
        }
    }
    return 0;
}