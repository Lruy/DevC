#include <iostream>
using namespace std;
typedef long long ll;

ll a[18]={};
ll getsum(){
    ll tttmp=0;
    for(int i=0;i<=17;i++)tttmp=tttmp*10+a[i];
    return tttmp;
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll tmp=0;
    for(int i=0;i<n;i++){ll ttmp;cin>>ttmp;tmp+=ttmp;}
    ll idx=17;
    while(tmp){
        a[idx]=tmp%10;
        idx--;
        tmp/=10;
    }
    idx++;
    ll ans=getsum();
    //cout<<ans<<'\n';
    for(int i=idx;i<=17;i++){
        for(int j=2;j<=k;j++){
            if(i+j-1>17)continue;
            for(int ii=0;ii<j/2;ii++){
                swap(a[i+ii],a[i+j-ii-1]);
            }
            ans=max(ans,getsum());
            //cout<<ans<<" "<<i<<" "<<j<<'\n';
            for(int ii=0;ii<j/2;ii++){
                swap(a[i+ii],a[i+j-ii-1]);
            }
        }
    }
    cout<<ans;
    return 0;
}