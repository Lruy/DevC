#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first<b.first;
}
pair<ll,ll> a[100005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        bool flag=true;
        for(int i=0;i<m;i++){
            ll t1,t2;
            cin>>t1>>t2;
            a[i]=make_pair(t1,t2);
        }
        sort(a,a+m,cmp);
        ll last1=0,last2=0;
        for(int i=0;i<m;i++){
            if(a[i].first-last1==a[i].second-last2||last2==0&&a[i].first-last1>=a[i].second||a[i].first-last1>a[i].second);
            else flag=false;
            last1=a[i].first;last2=a[i].second;
            if(!flag)break;
        }
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}