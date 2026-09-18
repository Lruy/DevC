#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n;
vector<ll> ys;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ys.push_back(y1);
        ys.push_back(y2);
        
    }
    return 0;
}