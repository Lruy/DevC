#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll k,z,sum;
int ans[100005];
int cnt[100005];
vector<ll> v;
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    memset(ans,-1,sizeof(ans));
    cin>>k>>z;

    for(int i=0;i<k;i++){
        cin>>cnt[i];
        sum+=cnt[i];
        if(cnt[i]==1){
            v.push_back(i);
        }
    }
    ll sz=v.size();
    bool al=true;
    for(int i=sz-1;i>=0;i--){
        ans[v[i]]=al;
        al^=1;
    }
    if((sum+z)%2){
        for(int i=k-1;i>=0;i--){
            if(cnt[i]){
                if(ans[i]==-1)cout<<"1";
                else if(ans[i]==0)cout<<"0";
                else cout<<"1";
            }
            else cout<<"0";
        }
    }
    else{
        for(int i=k-1;i>=0;i--){
            if(cnt[i]){
                if(ans[i]==-1)cout<<"0";
                else if(ans[i]==0)cout<<"0";
                else cout<<"1";
            }
            else cout<<"0";
        }
    }
    return 0;
}