#include <iostream>
using namespace std;
typedef long long ll;

ll dp[21][21][21];
ll w(ll a,ll b,ll c){
    if(a<=0||b<=0||c<=0)return 1;
    else if(a>20||b>20||c>20)return w(20,20,20);
    else if(a<b&&b<c){
        if(dp[a][b][c]==0)return dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        else return dp[a][b][c];
    }
    else {
        if(dp[a][b][c]==0)return dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        else return dp[a][b][c];
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t1,t2,t3;
    while(true){
        cin>>t1>>t2>>t3;
        if(t1==-1&&t2==-1&&t3==-1)break;
        else cout<<"w("<<t1<<", "<<t2<<", "<<t3<<") = "<<w(t1,t2,t3)<<'\n';
    }
    return 0;
}