#include <iostream>
using namespace std;
typedef long long ll;

ll n,m;
ll mp[500005];
inline ll lowbit(ll a){return a&(-a);}
ll count(ll a){return a?count(a-lowbit(a))+mp[a]:0;}
void add(ll a,ll b){while(a<=n){mp[a]+=b;a+=lowbit(a);}}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll t1;
        cin>>t1;
        add(i,t1);
    }
    while(m--){
        ll t1;
        cin>>t1;
        if(t1==1){
            ll t2,t3;
            cin>>t2>>t3;
            add(t2,t3);
        }
        else{
            ll t2,t3;
            cin>>t2>>t3;
            cout<<count(t3)-count(t2-1)<<'\n';
        }
    }
    return 0;
}