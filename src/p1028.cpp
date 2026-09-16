#include <iostream>
using namespace std;
typedef long long ll;

ll n;
ll dp[1005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j*2<=i;j++){
            dp[i]+=dp[j];
        }
        dp[i]++;
    }
    cout<<dp[n];
    return 0;
}