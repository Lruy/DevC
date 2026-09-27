#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll cnt=0;
    for(int i=1;;i++){
        if(cnt+i<=n){
            if(i-1)cout<<"\n";
            cout<<i;
            cnt+=i;
        }
        else{
            break;
        }
    }
    return 0;
}