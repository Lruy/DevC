#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Bigint{
    int a[5005];
    int strlen;
    Bigint(){}
    Bigint(ll aa,int bb){
        for(int i=0;i<bb;i++){
            this->a[i]=aa%10;
            aa/=10;
        }
    }
    Bigint operator+(Bigint &other){
        Bigint ans;
        int add=0;
        int len=max(this->strlen,other.strlen);
        for(int i=0;i<len;i++){
            int tmp=this->a[i]+other.a[i]+add;
            ans.a[i]=tmp%10;
            add=tmp/10;
        }
        if(add){
            ans.a[len]=add;
            len++;
        }
        ans.strlen=len;
        return ans;
    }
};


ll n;
Bigint dp[5005];
ll out[5005]={};
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    dp[0].a[0]=1;
    dp[0].strlen=1;
    dp[1].a[0]=1;
    dp[1].strlen=1;
    dp[2].a[0]=2;
    dp[2].strlen=1;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(int i=dp[n].strlen-1;i>=0;i--){
        if(i!=dp[n].strlen-1||dp[n].a[i])cout<<dp[n].a[i];
    }
    return 0;
}