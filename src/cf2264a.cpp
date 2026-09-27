#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[105];
ll b[105];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
        vector<ll> v;
        sort(b,b+n);
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])v.push_back(i);
        }
        bool flag=true;
        for(int i=0;i<v.size();i++){
            if(a[v[i]]!=b[v[v.size()-1-i]]){flag=false;break;}
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}