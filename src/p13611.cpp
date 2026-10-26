#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

signed main() {
    ll h1,h2,m1,m2,ans=0;
    scanf("%lld:%lld",&h1,&m1);
    scanf("%lld:%lld",&h2,&m2);
    if(m1>m2){
        ans+=m2+60-m1;
        h1++;
    }
    else ans+=m2-m1;
    if(h1>h2){
        ans+=h2+24-h1;
    }
    else ans+=h2-h1;
    cout<<ans;
    return 0;
}