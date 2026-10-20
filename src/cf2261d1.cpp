#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        if(n==1)cout<<"0\n";
        else if(n==2)cout<<"1\n1 1\n";
        else if(n==3)cout<<"2\n1 1\n2 2\n";
        else{
            cout<<(n+1)/2<<'\n';
            for(int i=1;i<=(n+1)/2;i++){
                cout<<i<<" "<<i-1+n/2<<'\n';
            }
        }
    }
    return 0;
}