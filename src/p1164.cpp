#include <iostream>
using namespace std;
typedef long long ll;

ll n,m;
ll dp[10005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    dp[0]=1;
    for(int i=0;i<n;i++){
        ll tmp;
        cin>>tmp;
        for(int i=m;i>=0;i--){
            if(dp[i] && (i+tmp)<=10000)dp[i+tmp]+=dp[i];
        }
    }
    cout<<dp[m];
    return 0;
}