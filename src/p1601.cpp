#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[505];
ll b[505];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string sa,sb;
    cin>>sa>>sb;
    for(int i=0;i<sa.size();i++){
        a[i]=sa[sa.size()-1-i]-'0';
    }
    for(int i=0;i<sb.size();i++){
        b[i]=sb[sb.size()-1-i]-'0';
    }
    ll add=0;
    ll len=max(sa.size(),sb.size());
    for(int i=0;i<len;i++){
        if(a[i]+b[i]+add>=10){
            a[i]+=b[i]+add;
            a[i]%=10;
            add=1;
        }
        else{
            a[i]+=b[i]+add;
            add=0;
        }
    }
    if(add){
        cout<<1;
    }
    for(int i=len-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}