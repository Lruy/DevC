#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll last;
        cin>>last;
        bool flag=true;
        for(int i=1;i<n;i++){
            ll tmp;
            cin>>tmp;
            if(tmp-last>1||last-tmp>x){
                flag=false;
            }
            last=tmp;
        }
        if(flag)cout<<"Win"<<'\n';
        else cout<<"Lose"<<'\n';
    }
    return 0;
}