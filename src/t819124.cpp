#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,r;
    cin>>n>>r;
    ll pos=n/2+1;
    for(int i=1;i<=n;i++){
        if(i-1)cout<<'\n';
        for(int j=1;j<=n;j++){
            if((i-pos)*(i-pos)+(j-pos)*(j-pos)<=r*r)cout<<"#";
            else cout<<".";
        }
    }
    return 0;
}