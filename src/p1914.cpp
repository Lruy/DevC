#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    string s;
    cin>>n>>s;
    ll sz=s.size();
    for(int i=0;i<sz;i++){
        ll tmp=s[i]-'a'+n;
        tmp%=26;
        tmp+='a';
        cout<<(char)tmp;
    }
    return 0;
}