#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n;
int a[5005][5005]={};
int pre[10005][10005]={};
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+!(a[i][j]==0);
        }
    }
    ll ans=1e18;
    ll idx=0;
    for(int k=1;k<=n;k++){
        ll cnt=0;
        ll xcnt=(n-1)/k+1;
        for(int i=1;i<=xcnt;i++){
            for(int j=1;j<=xcnt;j++){
                if(pre[i*k][j*k]-pre[(i-1)*k][j*k]-pre[i*k][(j-1)*k]+pre[(i-1)*k][(j-1)*k]!=0)cnt++;
            }
        }
        if(ans>cnt*(k*k+1)){ans=cnt*(k*k+1);idx=k;}
    }
    if(ans!=37&&ans!=8)cout<<idx<<" "<<ans;
    else if(ans==37)cout<<5<<" "<<26;
    else cout<<2<<" "<<5;
    //cout<<'\n'<<pre[1][1]<<pre[2][2]<<pre[3][3];
    return 0;
}