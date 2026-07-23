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
        ll tmp;
        cin>>tmp;
        add(i,tmp);
        add(i+1,-tmp);
    }
    while(m--){
        ll t1;
        cin>>t1;
        if(t1==1){
            ll t2,t3,t4;
            cin>>t2>>t3>>t4;
            add(t2,t4);
            add(t3+1,-t4);
        }
        else{
            ll t2;
            cin>>t2;
            cout<<count(t2)<<'\n';
        }
    }
    return 0;
}