#include<iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    ll n,l,r;
    cin>>n>>l>>r;
    cout<<r-l+1-(ll)sqrt(r)+(ll)sqrt(l-1);
    return 0;
}