#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,ans;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    ll pre=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ll sz=s.size();
        if(s[0]=='x'||s[sz-1]=='x'){
            ans=max(ans,pre);
            pre=0;
            continue;
        }
        ll xcnt=0;
        bool flag=true;
        for(int i=1;i<sz-1;i++){
            if(s[i]=='x')xcnt++;
            if(!(s[i]>='a'&&s[i]<='z')){
                flag=false;
                break;
            }
        }
        if(!flag||xcnt!=1){
            ans=max(ans,pre);
            pre=0;
            continue;
        }
        pre++;
        ans=max(ans,pre);
    }
    cout<<ans;
    return 0;
}