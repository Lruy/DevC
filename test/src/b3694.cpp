#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t,n;
ll a[100005];
vector<ll> ys;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ys.push_back(a[i]);
        }
        sort(ys.begin(),ys.end());
        ys.erase(unique(ys.begin(),ys.end()),ys.end());
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            ll idx=lower_bound(ys.begin(),ys.end(),a[i])-ys.begin();
            cout<<idx+1;
        }
        cout<<'\n';
        ys.clear();
    }
    return 0;
}