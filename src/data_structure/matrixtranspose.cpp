#include <iostream>
using namespace std;
typedef long long ll;
const ll c=6,r=7;
ll matrix[c][r]={{0,12,9},{},{-3,0,0,0,0,14},{0,0,24},{0,18},{15,0,0,-7}};
ll a[r*c][3];
ll idx;
ll presum[r]={-1};
ll b[r*c][3];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i=0;i<c;i++){for(int j=0;j<r;j++){if(j)cout<<"  ";if(matrix[i][j]>=0&&matrix[i][j]<10)cout<<" ";cout<<matrix[i][j];}cout<<'\n';}cout<<'\n';
    for(int i=0;i<c;i++)for(int j=0;j<r;j++)if(matrix[i][j]){a[idx][0]=i;a[idx][1]=j;a[idx++][2]=matrix[i][j];presum[j]++;}
    for(int i=1;i<c;i++)presum[i]+=presum[i-1];
    for(int i=0;i<idx;i++){for(int j=0;j<3;j++){if(j)cout<<" ";cout<<a[i][j];}cout<<'\n';}cout<<'\n';
    for(int i=idx-1;i>=0;i--){
        b[presum[a[i][1]]][0]=a[i][1];
        b[presum[a[i][1]]][1]=a[i][0];
        b[presum[a[i][1]]--][2]=a[i][2];
    }
    for(int i=0;i<idx;i++){
        if(i)cout<<'\n';
        bool first=true;
        for(int j=0;j<3;j++){
            if(!first)cout<<" ";first=false;
            cout<<b[i][j];
        }
    }
    return 0;
}