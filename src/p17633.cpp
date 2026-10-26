#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;

ll a[1005][1005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    ll sum=0;
    pair<ll,ll> pos;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll tmp;
            cin>>tmp;
            if(tmp!=-1)a[i][j]=tmp;
            else {
                pos.first=i;
                pos.second=j;
            }
        }
    }
    if(pos.first!=0&&pos.second!=0){cout<<a[pos.first+1][pos.second]+a[pos.first][pos.second+1]-a[pos.first+1][pos.second+1];}
    else if(pos.first!=n-1&&pos.second!=n-1){cout<<a[pos.first-1][pos.second]+a[pos.first][pos.second-1]-a[pos.first-1][pos.second-1];}
    else if(pos.first!=n-1&&pos.second!=0){cout<<a[pos.first-1][pos.second]+a[pos.first][pos.second+1]-a[pos.first-1][pos.second+1];}
    else {cout<<a[pos.first+1][pos.second]+a[pos.first][pos.second-1]-a[pos.first+1][pos.second-1];}
    return 0;
}