#include <iostream>
using namespace std;
typedef long long ll;

int fat[100005];
int n,q;
int find(int x){
    if(fat[x]<0)return x;
    else return fat[x]=find(fat[x]);
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<=n;i++)fat[i]=-1;
    while(q--){
        int tmp;
        cin>>tmp;
        if(tmp==1){
            int a,b;
            cin>>a>>b;
            int rootA=find(a);
            int rootB=find(b);
            if(rootA!=rootB){
                if(fat[rootA]>=fat[rootB]){
                    fat[rootB]+=fat[rootA];
                    fat[rootA]=rootB;
                }
                else{
                    fat[rootA]+=fat[rootB];
                    fat[rootB]=rootA;
                }
            }
        }
        else{
            int a,b;
            cin>>a>>b;
            if(find(a)==find(b))cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}