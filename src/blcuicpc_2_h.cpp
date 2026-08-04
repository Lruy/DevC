#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,k,ans;
ll fat[150005];
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
    cin>>n>>k;
    memset(fat,-1,sizeof(fat));
    for(int i=1;i<=k;i++){
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        if(t2>n || t3>n || t1==2 && t2==t3){
            ans++;
            continue;
        }
        if(t1==1){
            ll fa[3],fb[3];
            for(int i=0;i<3;i++){
                fa[i]=find(t2+i*n);
                fb[i]=find(t3+i*n);
            }
            if(fa[0]==fb[1] || fa[0]==fb[2] || fa[1]==fb[0] || fa[1]==fb[2] || fa[2]==fb[0] || fa[2]==fb[1]){
                ans++;
                continue;
            }
            else{
                merge(t2,t3);
                merge(t2+n,t3+n);
                merge(t2+2*n,t3+2*n);
            }
        }
        else{
            ll fa[3],fb[3];
            for(int i=0;i<3;i++){
                fa[i]=find(t2+i*n);
                fb[i]=find(t3+i*n);
            }
            if(fa[0]==fb[0] || fa[0]==fb[2] || fa[1]==fb[0] || fa[1]==fb[1] || fa[2]==fb[2] || fa[2]==fb[1]){
                ans++;
                continue;
            }
            else{
                merge(t2,t3+n);
                merge(t2+n,t3+2*n);
                merge(t2+2*n,t3);
            }
        }
    }
    cout<<ans;
    return 0;
}