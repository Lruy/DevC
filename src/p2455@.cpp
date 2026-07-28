#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
double m[55][55];
double ans[55];
const double eps=1e-9;
double abss(double a){
    if(a<0)return -a;
    else return a;
}
vector<int> er;
int pivot_row[55];

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>m[i][j];
        }
    }
    int r=0;
    for(int c=0;c<n;c++){
        int idx=r;
        for(int j=r+1;j<n;j++){
            if(abss(m[j][c])>abss(m[idx][c]))idx=j;
        }
        if(abss(m[idx][c])<eps){
            er.push_back(c);
            continue;
        }
        if(idx!=r)swap(m[idx],m[r]);
        for(int j=n;j>=c;j--)m[r][j]/=m[r][c];
        for(int j=r+1;j<n;j++){
            for(int k=n;k>=c;k--)m[j][k]-=m[j][c]*m[r][k];
        }
        pivot_row[c]=r;
        r++;
    }
    for(int i=r;i<n;i++){
        if(abss(m[i][n])>eps){
            cout<<"-1";
            return 0;
        }
    }
    if(r<n){
        cout<<"0";
        return 0;
    }
    for(int c=n-1;c>=0;c--){
        int row=pivot_row[c];
        ans[c]=m[row][n];
        for(int j=c+1;j<n;j++)ans[c]-=ans[j]*m[row][j];
    }
    for(int i=1;i<=n;i++){
        printf("x%d=%.2lf\n",i,ans[i-1]);
    }
    return 0;
}
