#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll ar[200005];
bool cmp(ll a,ll b){
	ll cnta=0,cntb=0,tmpa=a,tmpb=b;
	while(tmpa){
		ll tmp=tmpa%10;
		if(tmp==4)cnta++;
		else if(tmp==6)cnta++;
		else if(tmp==8)cnta+=2;
		else if(tmp==9)cnta++;
        else if(tmp==0)cnta++;
		tmpa/=10;
	}
	while(tmpb){
		ll tmp=tmpb%10;
		if(tmp==4)cntb++;
		else if(tmp==6)cntb++;
		else if(tmp==8)cntb+=2;
		else if(tmp==9)cntb++;
        else if(tmp==0)cntb++;
		tmpb/=10;
	}
	if(cnta!=cntb)return cnta<cntb;
	else return a<b;
}
ll n;
signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n,cmp);
	for(int i=0;i<n;i++){
		if(i)cout<<" ";
		cout<<ar[i];
	}
	return 0;
} 