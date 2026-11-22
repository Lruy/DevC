#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[7],k,ot[7];
bool c;
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(ll i=1;i<=6;i++) {cin>>a[i];a[i]++;}
    sort(a,a+6);
    a[0]=1;
    cin>>k;
    for(int i=0;i<=6;i++){
        for(int ii=0;ii<=6;ii++){
            for(int iii=0;iii<=6;iii++){
                for(int iiii=0;iiii<=6;iiii++){
                    for(int iiiii=0;iiiii<=6;iiiii++){
                        for(int j=0;j<=6;j++){
                            if(i+ii+iii+iiii+iiiii+j>=19){
                                if(c)continue;
                                ll cost=a[i]+a[ii]+a[iii]+a[iiii]+a[iiiii]+a[j];
                                if(cost<=k){
                                    ot[1]=a[i];
                                    ot[2]=a[ii];
                                    ot[3]=a[iii];
                                    ot[4]=a[iiii];
                                    ot[5]=a[iiiii];
                                    ot[6]=k-ot[1]-ot[2]-ot[3]-ot[4]-ot[5];
                                    c=true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(c){
        cout<<"YES\n";
        for(int i=1;i<=6;i++){
            if(i-1)cout<<" ";
            cout<<ot[i];
        } 
    }
    else cout<<"NO";
    return 0;
}