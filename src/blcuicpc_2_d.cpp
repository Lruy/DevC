#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,m;
ll fat[200005];
ll find(ll a){
    if(fat[a]<0)return a;
    else return fat[a]=find(fat[a]);
}
void merge(ll a,ll b){
    ll roota=find(a);
    ll rootb=find(b);
    if(roota!=rootb){
        if(fat[roota]<fat[rootb]){fat[roota]+=fat[rootb];fat[rootb]=roota;}
        else {fat[rootb]+=fat[roota];fat[roota]=rootb;}
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(fat,-1,sizeof(fat));
    while(m--){
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        if(t1==1){
            merge(t2,t3);
        }
        else{
            if(find(t2)==find(t3))cout<<"Y\n";
            else cout<<"N\n";
        }
    }
    return 0;
}