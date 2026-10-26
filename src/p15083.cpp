#include <iostream>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll t1,t2,t3;
    cin>>t1>>t2>>t3;
    cout<<"100\n";
    cout<<t1;
    for(int i=1;i<50;i++)cout<<" "<<t1;
    for(int i=0;i<45;i++)cout<<" "<<t2;
    for(int i=0;i<4;i++)cout<<" "<<t3;
    cout<<" "<<t3+1;
    return 0;
}