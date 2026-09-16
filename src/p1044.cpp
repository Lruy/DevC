#include <iostream>
using namespace std;
typedef long long ll;

ll n;
ll dp[20][20];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(!i) dp[i][j]=1;
            else if(!j)dp[i][j]=dp[i-1][j+1];
            else dp[i][j]=dp[i-1][j+1]+dp[i][j-1];
        }
    }
    cout<<dp[n][0];
    return 0;
}