#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll t,n,cnt,ava,tot;
ll a[200005];
bool cost[33];
inline ll fastpower(ll a){
    ll tmp=2;
    ll ans=1;
    while(a){
        if(a&1)ans*=tmp;
        a>>=1;
        tmp*=tmp;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(cost,0,sizeof(cost));
        cnt=0;
        ava=0;
        tot=0;
        vector<ll> v;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=32;i>=0;i--){
            if(v.empty()){
                bool find=false;
                ll vcnt=0;
                ll usedava=0;
                bool beava=false;
                for(int j=0;j<n;j++){
                    if(!find && (a[j]>>i&1)==1){
                        find=true;
                        vcnt++;
                        v.push_back(j);
                    }
                    else if(find && (a[j]>>i&1)==0){
                        if(usedava+1>ava){
                            cost[i]=true;
                            ava+=fastpower(cnt);
                            cnt++;
                            beava=true;
                            while(vcnt--){v.pop_back();}
                            break;
                        }
                        else{
                            usedava++;
                            find=false;
                            vcnt++;
                            v.push_back(j);
                            continue;
                        }
                    }
                }
                if(!beava)ava-=usedava;
            }
            else{
                ll vcnt=0;
                ll sz=v.size();
                sort(v.begin(),v.end());
                v.erase(unique(v.begin(),v.end()),v.end());
                sz=v.size();
                ll ta=0,tb=0;
                ll usedava=0;
                bool beava=false;
                for(int k=0;k<=sz;k++){
                    bool find=false;
                    ta=tb;
                    if(k==sz)tb=n;
                    else tb=v[k];
                    ll seg_usedava=0;
                    for(int j=ta;j<tb;j++){
                        if(!find && (a[j]>>i&1)==1){
                            find=true;
                            vcnt++;
                            v.push_back(j);
                        }
                        else if(find && (a[j]>>i&1)==0){
                            if(usedava+1>ava){
                                cost[i]=true;
                                ava+=fastpower(cnt);
                                cnt++;
                                beava=true;
                                break;
                            }
                            else{
                                usedava++;
                                seg_usedava++;
                                find=false;
                                vcnt++;
                                v.push_back(j);
                                continue;
                            }
                        }
                    }
                    if(beava)break;
                }
                if(!beava)ava-=usedava;
                else while(vcnt--){v.pop_back();}
            }
        }
        for(int i=32;i>=0;i--){
            if(cost[i])tot+=1<<i;
        }
        cout<<tot<<'\n';
    }
    return 0;
}
