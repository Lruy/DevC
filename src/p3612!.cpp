#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,len;
string s;
void loop(ll leng){
    if(leng<n){
        loop(leng*2);
    }
    else{
        if(n<len){
            cout<<s[n-1];
            return;
        }
        if(n>(leng/2))n=(n-1-leng/2+n)%n;
        loop(leng/2);
    }
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    cin>>n;
    len=s.size();
    return 0;
}