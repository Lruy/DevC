#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n;
int fat[100005];
int sub[100005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    fat[0]=0;fat[1]=1;
    for(int i=2;i<=n;i++){
        cin>>fat[i];
    }
    for(int i=2;i<=n;i++){
        int tmp=i;
        sub[fat[tmp]]++;
        while(fat[tmp]!=1 && tmp!=1){
            tmp=fat[tmp];
            sub[fat[tmp]]++;
        }
    }
    bool first=true;
    for(int i=1;i<=n;i++){
        if(!first)cout<<" ";
        first=false;
        cout<<sub[i];
    }
    return 0;
}