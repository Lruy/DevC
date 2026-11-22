#include <iostream>
using namespace std;
typedef long long ll;
const ll N=5;

ll matrix[N][N]={{1,2,0,0,0},{6,8,3,0,0},{0,5,7,9,0},{0,0,2,3,1},{0,0,0,3,4}};
ll a[N*N];
ll idx,cnt;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i=0;i<N;i++)for(int j=i-1;j<=i+1;j++)if(j>=0&&j<N)a[idx++]=matrix[i][j];
    for(int i=0;i<N;i++){
        if(i)cout<<'\n';
        bool first=true;
        for(int j=0;j<i-1;j++){
            if(!first)cout<<" ";first=false;
            cout<<"0";
        }
        for(int j=i-1;j<=i+1;j++){
            if(j>=0&&j<N){
                if(!first)cout<<" ";first=false;
                cout<<a[cnt++];
            }
        }
        for(int j=i+2;j<N;j++){
            if(!first)cout<<" ";first=false;
            cout<<"0";
        }
    }
    return 0;
}