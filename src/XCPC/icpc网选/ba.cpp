#include<iostream>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
ll n,p,a[100000],c;
void solve(){
    set<ll> st;
    map<ll,ll> mp;
    ll bg=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(ll i=0;i<=n;i++){
        if(!mp[i]){
            bg=i;
            break;
        }
    }
    for(ll i=0;i<n;i++){
        st.insert(a[i]+bg);
    }
    for(ll i:st){
        for(ll j=bg;j<=n;j++){
            if(j<i-j){
                if(!mp[j]&&!mp[i-j]){
                    mp[i]=j;
                    break;
                }
            }
            else{
                if(mp[j]+mp[i-j]<2){
                    mp[i]=j;
                    break;
                }
            }
        }
    }
    ll ans=0;
    cin>>p;
    while(p--){
        cin>>c;
        if(mp[c]){
            ans^=mp[c];
        }
        else{
            ans^=bg;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--) solve();
    return 0;
}