#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,m;
bool rev[100005];
string nm[100005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>rev[i];
        cin>>nm[i];
    }
    ll aim=0;
    while(m--){
        bool tmp;
        cin>>tmp;
        ll tmpp;
        cin>>tmpp;
        if(tmp^rev[aim]){
            aim=((aim+tmpp)%n+n)%n;
        }
        else{
            aim=((aim-tmpp)%n+n)%n;
        }
    }
    cout<<nm[aim];
    return 0;
}