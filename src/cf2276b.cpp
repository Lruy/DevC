#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll sz=s.size();
        ll cnt=1;
        ll flag0=false,flag1=false;
        for(int i=2;i<sz;i++){
            if(s[i]=='0'&&s[i-1]=='0'&&s[i-2]=='0')flag0=true;
            if(s[i]=='1'&&s[i-1]=='1'&&s[i-2]=='1')flag0=true;
            if(s[i]=='1'&&s[i-1]=='0'&&s[i-2]=='1')flag1=true;
            if(s[i]=='0'&&s[i-1]=='1'&&s[i-2]=='0')flag1=true;
        }
        cout<<cnt+flag0+flag1<<'\n';
    }
    return 0;
}