//高斯-约旦消元法 Gauss-Jordan Elimination
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const double eps=1e-7;
double mp[105][105];
double abss(double x){
	if(x<0)x=-x;
	return x;
}
int n,r;
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n+1;j++){
			cin>>mp[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int idx=r;
		for(int j=r+1;j<n;j++){
			if(abss(mp[j][i])>abss(mp[idx][i])){
				idx=j;
			}
		}
		if(abss(mp[idx][i])<eps){
			continue;
		}
		if(r!=idx)swap(mp[r],mp[idx]);
		for(int j=n;j>=i;j--)mp[r][j]/=mp[r][i];
		for(int j=0;j<n;j++){
			if(j==r)continue;
			for(int k=i+1;k<n+1;k++)mp[j][k]-=mp[j][i]*mp[r][k];
			mp[j][i]=0;
		}
		r++;
	}
	if(r<n){
		for(int i=r;i<n;i++){
			if(abss(mp[i][n])>eps){
				cout<<"-1";
				return 0;
			}
		}
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++){
		printf("%.2f\n",mp[i][n]);
	}
	return 0;
}