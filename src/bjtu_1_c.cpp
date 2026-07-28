#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Lim{
    int l,r,h;
    Lim(int x,int y,int z){
        l=x;
        r=y;
        h=z;
    }
    Lim(){
        l=0;
        r=0;
        h=0;
    }
    bool operator<(Lim &x){
        return this->h<x.h;
    }
};
int d,n;
Lim m[10005];
int mm[366];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>d>>n;
    for(int i=0;i<n;i++){
        cin>>m[i].l>>m[i].r>>m[i].h;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(m[j]<m[i]){
                swap(m[j],m[i]);
            }
        }
    }
    int ds=0;
    int idx=0;
    int ans=0;
    while(ds<d){
        for(int i=m[idx].l;i<=m[idx].r;i++){
            if(mm[i]==0){
                mm[i]=m[idx].h;
                ds++;
                ans+=m[idx].h;
            }
        }
        idx++;
    }
    cout<<ans;
    return 0;
}