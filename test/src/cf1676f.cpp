#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t,n,k;
map<ll,ll> mp;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>t;
    while(t--){
        mp.clear();                                           // Bug1: 必须清空！
        cin>>n>>k;
        for(int i=0;i<n;i++){
            ll tmp;
            cin>>tmp;
            mp[tmp]++;
        }
        ll tmp=0,tmpl=0,ans=0,ansl=0,ansr=0,last=-1,update=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(last==-1){
                if(it->second>=k){
                    tmpl=it->first;
                    tmp=1;
                    last=tmpl;
                    update=0;
                    continue;
                }
                else{
                    update=0;
                    continue;
                }
            }
            else if(last+1!=it->first){
                if(tmp>ans){
                    ans=tmp;
                    ansl=tmpl;
                    ansr=last;
                }
                if(it->second>=k){
                    tmpl=it->first;
                    tmp=1;
                    last=tmpl;
                    update=1;
                    continue;
                }
                else{
                    tmp=0;
                    tmpl=0;
                    last=-1;
                    update=1;
                    continue;
                }
            }
            else{
                if(it->second>=k){
                    tmp++;
                    last=it->first;
                    update=0;
                    continue;
                }
                else{
                    if(tmp>ans){
                        ans=tmp;
                        ansl=tmpl;
                        ansr=last;
                    }
                    tmp=0;
                    tmpl=0;
                    last=-1;
                    update=1;
                    continue;
                }
            }
        }
        if(!update){
            if(tmp>ans){
                ans=tmp;
                ansl=tmpl;
                ansr=last;
            }
        }
        if(ans)cout<<ansl<<" "<<ansr<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}