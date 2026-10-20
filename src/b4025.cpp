#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    else return gcd(b,a%b); 
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    cout<<gcd(n,m);
    return 0;
}