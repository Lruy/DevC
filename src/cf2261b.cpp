#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll mmin=-1,mmax=-1;
        for(int i=0;i<n;i++){
            ll tmp;cin>>tmp;
            if(mmin==-1){mmin=mmax=tmp;}
            else{
                mmin=min(mmin,tmp);
                mmax=max(mmax,tmp);
            }
        }
        if(mmin==mmax)cout<<mmax<<'\n';
        else{
            ll tmp;
            for(int i=32;i>=0;i--){
                tmp=mmax>>i;
                tmp<<=i;
                //cout<<mmax<<" "<<mmin<<" "<<tmp<<'\n';
                if(mmin<tmp){
                    break;
                }
            }
            cout<<(mmax|tmp-1)<<'\n';
        }
    }
    return 0;
}