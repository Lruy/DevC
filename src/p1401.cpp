#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    ll la=a,lb=b,lc=c,ld=d;
    if(a*c!=la*lc||a*d!=la*ld||b*c!=lb*lc||b*d!=lb*ld)cout<<"long long int";
    else cout<<"int";
    return 0;
}