#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define GCM 2520

vector<ll> a;
vector<ll> dp;
ll loc[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
ll n;
ll gcd(ll a,ll b){
    ll temp;
    while(a%b!=0){
        temp=a;
        a=b;
        b=temp%a;
    }
    return b;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        a.push_back(temp);
    }
    vector<ll> dp(n+1,1e18);
    dp[0]=0;
    loc[a[0]]=0;
    for(int i=1;i<n;i++){
        //teleport
        if(loc[a[i]]!=-1 && abs(i-loc[a[i]])>1){
            dp[i]=min(dp[i],dp[loc[a[i]]]+GCM);
        }
        loc[a[i]]=i;
        //long pass
        for(int j=i-1;j>=i-9 && j>=0;j--){
            if(a[j]>=(i-j)){
                dp[i]=min(dp[i],dp[j]+(i-j)*GCM/a[j]);
            }
        }
    }
    ll tmp=gcd(dp[n-1],2520);
    cout<<(dp[n-1]/tmp)<<" "<<2520/tmp;
    return 0;
}