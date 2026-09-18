#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

int n,m;
int fat[100005];
int bfind(int x){
    if(fat[x]<0){
        return x;
    }
    else return fat[x]=bfind(fat[x]);
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fat[i]=-1;
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        int rootA = bfind(a);
        int rootB = bfind(b);
        if(rootA != rootB){
            fat[rootB] = rootA;
        }
        // if(fat[a]>0 && fat[b]>0){
        //     fat[bfind(b)]=bfind(a);
        // }
        // else if(fat[a]>0){
        //     fat[b]=bfind(a);
        // }
        // else if(fat[b]>0){
        //     fat[a]=bfind(b);
        // }
        // else fat[b]=a;
    }
    int afat=bfind(1);
    for(int i=1;i<=n;i++){
        if(bfind(i)!=afat){
            cout<<"The graph is not connected.";
            return 0;
        }
    }
    cout<<"The graph is connected.";
    return 0;
}