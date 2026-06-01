#include <iostream>
using namespace std;
typedef long long ll;

int n,m,b;
ll ans;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m>>b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ans+=temp*m;
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        ans+=temp*n;
    }
    ans+=b*n*m;
    cout<<ans;
    return 0;
}