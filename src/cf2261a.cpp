#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll min=-1,max=-1;
        ll cnt=0;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(min==-1&&ch=='1'){min=max=i;cnt++;}
            else if(ch=='1'){
                max=i;cnt++;
            }
        }
        if(cnt==1)cout<<"0\n";
        else if(cnt==2)cout<<"1\n";
        else cout<<max-min<<'\n';

    }
    return 0;
}