#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    while(cin>>n){
        if(n==0)return 0;
        else{
            int mp[100005]={};
            for(int i=0;i<n;i++){
                int t1,t2;
                cin>>t1>>t2;
                mp[t1]++;
                mp[t2+1]--;
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                if(i-1)cout<<" ";
                ans+=mp[i];
                cout<<ans;
           }
           cout<<'\n';
        }
    }
    return 0;
}