#include <iostream>
using namespace std;
typedef long long ll;

ll n,k;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>k;
    if(k+2-2*n>=0 && (k+2-2*n)%2==0)cout<<"Yes";
    else cout<<"No";
    return 0;
}