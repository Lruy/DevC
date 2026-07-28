//高斯-约旦消元法 Gauss-Jordan Elimination
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const double eps=1e-7;
double mp[105][105];
double abss(double x){
	if(x<0)return -x;
	return x;
}
int n;
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n+1;j++){
			cin>>mp[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int idx=i;
		for(int j=i+1;j<n;j++){
			if(abss(mp[j][i])>abss(mp[idx][i])){
				idx=j;
			}
		}
		if(abss(mp[idx][i])<eps){
			cout<<"No Solution";
			return 0;
		}
		if(i!=idx)swap(mp[i],mp[idx]);
		for(int j=n;j>=i;j--)mp[i][j]/=mp[i][i];
		for(int j=0;j<n;j++){
			if(j==i)continue;
			for(int k=i+1;k<n+1;k++)mp[j][k]-=mp[j][i]*mp[i][k];
			mp[j][i]=0;
		}
	}
	for(int i=0;i<n;i++){
		printf("%.2f\n",mp[i][n]);
	}
	return 0;
}