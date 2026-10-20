#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll flag=-1;
    for(int i=1;i<=4;i++){
        ll t1,t2,t3;
        if(i==1){t1=a;t2=b;t3=c;}
        else if(i==2){t1=a;t2=b;t3=d;}
        else if(i==3){t1=a;t2=c;t3=d;}
        else if(i==4){t1=d;t2=b;t3=c;}
        if(t1+t2>t3 && t1+t3>t2 && t2+t3>t1)flag=max(flag,1LL);
        else if(t1+t2==t3 || t1+t3==t2||t2+t3==t1)flag=max(flag,0LL);
    }
    if(flag==1)cout<<"TRIANGLE";
    else if(flag==0)cout<<"SEGMENT";
    else cout<<"IMPOSSIBLE";
    return 0;
}