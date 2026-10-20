#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(k%2==0)cout<<"YES\n";
        else if(k==1){
            if(n>1)cout<<"NO\n";
            else cout<<"YES\n";
        }
        else{
            if(n%k<=k/2&&(n/k-n%k)<=1)cout<<"YES\n";
            else if(n%k>k/2&&(n/k-k/2+(n%k-k/2)<=1))cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}