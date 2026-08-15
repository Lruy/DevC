#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m;
ll cnt[1005];
ll fa[1005];
ll find(ll a){
    if(fa[a]<0)return a;
    else return fa[a]=find(fa[a]);
}
void merge(ll a,ll b){
    ll roota=find(a);
    ll rootb=find(b);
    if(roota!=rootb){
        if(fa[roota]<fa[rootb]){
            fa[roota]+=fa[rootb];
            fa[rootb]=roota;
        }
        else{
            fa[rootb]+=fa[roota];
            fa[roota]=rootb;
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n!=0){
        cin>>m;
        memset(cnt,0,sizeof(cnt));
        memset(fa,-1,sizeof(fa));
        for(int i=0;i<m;i++){
            ll t1,t2;
            cin>>t1>>t2;
            cnt[t1]++;
            cnt[t2]++;
            merge(t1,t2);
        }
        ll ans=0;
        ll fat=find(1LL);
        for(int i=1;i<=n;i++){
            if(cnt[i]%2)ans++;
            if(find(i)!=fat){
                ans=-1;
                break;
            }
        }
        if(ans==0)cout<<"1\n";
        else cout<<"0\n";
        cin>>n;
    }
    return 0;
}