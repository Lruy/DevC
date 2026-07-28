#include <iostream>
using namespace std;
typedef long long ll;

ll t,k;
ll yh[2005][2005];
ll pre[2005][2005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>t>>k;
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)yh[i][j]=1;
            else yh[i][j]=((yh[i-1][j-1]%k)+(yh[i-1][j]%k))%k;
        }
    }
    if(yh[0][0]%k==0)pre[0][0]=1;
    for(int i=1;i<=2000;i++){
        pre[0][i]=pre[0][i-1]+pre[0][0];
        pre[i][0]=pre[0][0];
    }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=2000;j++){
            if(j<=i){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
                if(yh[i][j]%k==0)pre[i][j]++;
            }
            else pre[i][j]=pre[i][i];
        }
    }
    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<<pre[n][m]<<'\n';
    }
    return 0;
}