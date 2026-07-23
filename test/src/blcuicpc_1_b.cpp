#include <iostream>
using namespace std;
typedef long long ll;

int n,m;
int mp[1005][1005];
int pre[1005][1005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
            mp[x1][y1]++;
            mp[x1][y2+1]--;
            mp[x2+1][y1]--;
            mp[x2+1][y2+1]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]=mp[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            if(j-1)cout<<" ";
            cout<<pre[i][j];
        }
        cout<<'\n';
    }
    return 0;
}