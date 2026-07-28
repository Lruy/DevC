#include <iostream>
using namespace std;
typedef long long ll;

int n;
int sub[100005];
int fat[100005];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>fat[i];
        sub[fat[i]]++;
    }
    for(int i=n;i>=2;i--){
        sub[fat[i]]+=sub[i];
    }
    for(int i=1;i<=n;i++){
        if(i>1)cout<<" ";
        cout<<sub[i];
    }
    return 0;
}