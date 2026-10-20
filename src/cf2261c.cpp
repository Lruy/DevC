#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            ll tmp;
            cin>>tmp;
            if(tmp%2==1)cnt1++;
            else cnt2++;
        }
        if(cnt1%2==0)cout<<"Moggity"<<'\n';
        else if(cnt1==1){
            if(cnt2==0)cout<<"Moggity"<<'\n';
            else if(cnt2==1) cout<<"Larpity"<<'\n';
            else cout<<"Moggity"<<'\n';
        }
        else if(cnt1==3){
            if(cnt2==0)cout<<"Larpity"<<'\n';
            else cout<<"Moggity"<<'\n';
        }
        else{
            cout<<"Moggity"<<'\n';
        }
    }
    return 0;
}