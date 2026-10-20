#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

set<ll> s;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;cin>>n;
    for(int i=0;i<n;i++){ll tmp;cin>>tmp;s.insert(tmp);}
    cout<<s.size()<<'\n';
    for(auto it=s.begin();it!=s.end();it++){if(it!=s.begin())cout<<" ";cout<<*it;}
    return 0;
}