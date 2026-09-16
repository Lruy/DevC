#include <iostream>
using namespace std;
typedef long long ll;

ll n,m;
ll cnt[105][105];
ll dx[8]={-1,0,1,1,1,0,-1,-1};
ll dy[8]={1,1,1,0,-1,-1,-1,0};
bool bom[105][105];
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char tmp;
            cin>>tmp;
            if(tmp=='*'){
                bom[i][j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(bom[i][j])cout<<"*";
            else{
                ll cntt=0;
                for(int k=0;k<8;k++){
                    if(bom[i+dx[k]][j+dy[k]])cntt++;
                }
                cout<<cntt;
            }
        }
        cout<<'\n';
    }
    return 0;
}