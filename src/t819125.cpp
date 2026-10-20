#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

bool primes[105]={};
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i=2;i<=100;i++){
        bool flag=true;
        for(int j=2;j<i;j++){
            if(i%j==0){flag=false;break;}
        }
        if(flag)primes[i]=true;
    }
    string s;
    cin>>s;
    ll sz=s.size();
    ll ans=0;
    for(int i=1;i<sz;i++){
        ll tmp=(s[i-1]-'0')*10+(s[i]-'0');
        if(primes[tmp])ans+=tmp;
    }
    cout<<ans;
    return 0;
}