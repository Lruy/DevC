#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

ll n,m;
ll a[1005];
ll idx[1005];
ll fin[1005];
vector<ll> v;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>fin[i];
    n=3;fin[1]=2;fin[2]=3;fin[3]=1;
    for(int i=1;i<=n;i++){a[i]=i;idx[i]=i;}
    for(int i=1;i<=n;i++){
        ll tar=fin[i];
        for(int j=idx[tar]+1;j<=n;j++){
            idx[a[j-1]]++;
            idx[a[j]]--;
            swap(a[j-1],a[j]);
            v.push_back(a[j-1]);
            v.push_back(a[j]);
            m++;
        }
        for(int j=n;j>=i+1;j--){
            idx[j-1]++;
            idx[j]--;
            swap(a[j-1],a[j]);
            v.push_back(a[j-1]);
            v.push_back(a[j]);
            m++;
        }
    }
    cout<<m<<'\n';
    ll sz=v.size();
    for(int i=0;i<sz;i++){
        if(i%2==0)cout<<v[i]<<" ";
        else cout<<v[i]<<'\n';
    }
    return 0;
}