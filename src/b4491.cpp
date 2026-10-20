#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll cnt=0,xx,yy,z;
    cin>>xx>>yy>>z;
    for(int i=10;i<=99;i++){
        for(int j=10;j<=99;j++){
            ll x=i,y=j,c=0;
            while(c<z){
                if((x+y)%2==1)x-=y%x;
                else y-=x%y;
                if(x<c)x+=y/2+1;
                if(y<c)y+=x/2+1;
                c++;
            }
            if(x==xx&&y==yy)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}