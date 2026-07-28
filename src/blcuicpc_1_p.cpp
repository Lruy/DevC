#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=998244353;

ll power(ll a, ll b) {
    ll tmp=1;
    a%=MOD;
    while(b){
        if(b&1)tmp=(tmp*a)%MOD;
        b>>=1;
        a=(a*a)%MOD;
    }
    return tmp;
}
int t;
ll dif2[100005]={};
ll dif3[100005]={};
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        while(m--){
            ll t1,t2,t3;
            cin>>t1>>t2>>t3;
            if(t3==2){
                dif2[t1]++;
                dif2[t2+1]--;
            }
            else{
                dif3[t1]++;
                dif3[t2+1]--;
            }
        }
        ll t2=0;
        ll min2=dif2[1];
        ll t3=0;
        ll min3=dif3[1];
        for(int i=1;i<=n;i++){
            t2+=dif2[i];
            min2=min(min2,t2);
            t3+=dif3[i];
            min3=min(min3,t3);
        }
        if(min2 && min3)cout<<power(2,min2)*power(3,min3)%MOD;
        else if(min3)cout<<power(3,min3)%MOD;
        else if(min2)cout<<power(2,min2)%MOD;
        else cout<<"1";
        cout<<'\n';
        for(int i=0;i<=n+1;i++){
            dif2[i]=0;
            dif3[i]=0;
        }
    }
    return 0;
}