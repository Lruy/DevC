#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll k;
    cin>>k;
    for(int i=1;;i++){
        ll tar=0,cnt=0;
        bool flag=true;
        while(cnt<k){
            tar+=i%(2*k-cnt)-1;
            tar+=2*k-cnt;
            tar%=2*k-cnt;
            cnt++;
            if(tar<k){flag=false;break;}
        }
        if(flag){cout<<i;return 0;}
    }
    return 0;
}