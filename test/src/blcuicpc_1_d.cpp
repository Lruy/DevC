#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int n,m,ans;
int mp[5005][5005];
int pre[5005][5005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(n--){
        int x,y,v;
        cin>>x>>y>>v;
        mp[x][y]+=v;
    }
    pre[0][0]=mp[0][0];
    for(int i=1;i<=5000;i++){
        pre[i][0]=pre[i-1][0]+mp[i][0];
        pre[0][i]=pre[0][i-1]+mp[0][i];
    }
    for(int i=1;i<=5000;i++){
        for(int j=1;j<=5000;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+mp[i][j];
        }
    }
    ans=pre[m-1][m-1];
    for(int i=m;i<=5000;i++){
        ans=max(ans,pre[i][m-1]-pre[i-m][m-1]);
        ans=max(ans,pre[m-1][i]-pre[m-1][i-m]);
    }
    for(int i=m;i<=5000;i++){
        for(int j=m;j<=5000;j++){
            ans=max(ans,pre[i][j]-pre[i-m][j]-pre[i][j-m]+pre[i-m][j-m]);
        }
    }
    cout<<ans;
    return 0;
}