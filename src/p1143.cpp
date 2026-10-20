#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    string s;
    cin>>s;
    ll m;
    cin>>m;
    for(int i=0;i<s.size();i++){
        ans*=n;
        if(s[i]>='0'&&s[i]<='9')ans+=(s[i]-'0');
        else ans+=(s[i]-'A'+10);
    }
    //cout<<ans<<'\n';
    string ss="";
    while(ans){
        ll tmp=ans%m;
        if(tmp>=0&&tmp<=9){
            char t='0';
            t+=tmp;
            ss+=t;
        }
        else{
            char t='A';
            t+=(tmp-10);
            ss+=t;
        }
        ans/=m;
    }
    for(int i=ss.size()-1;i>=0;i--){
        cout<<ss[i];
    }
    return 0;
}