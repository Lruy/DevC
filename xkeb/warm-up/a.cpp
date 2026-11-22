#include <iostream>
using namespace std;
typedef long long ll;

ll n;
ll cnt[7];
ll num[100005][7];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i=1;i<7;i++)cin>>cnt[i];
    for(int i=1;i<7;i++)num[0][i]=cnt[i];
    cin>>n;
    for(int i=1;i<=n;i++){
        ll t1,t2,t3;
        cin>>t1>>t2>>t3;
        if(t1==1){
            if(cnt[1]!=0&&t2!=1&&t3!=1&&t2!=t3){
                cnt[1]--;
                cnt[t2]=cnt[t2]^cnt[t3];
                cnt[t3]=cnt[t2]^cnt[t3];
                cnt[t2]=cnt[t2]^cnt[t3];
                
            }
        }
        else if(t1==2){
            if(cnt[2]!=0&&t2!=2&&t3<i){
            cnt[2]--;
            cnt[t2]=num[t3][t2];
            }
        }
        else if(t1==3){if(cnt[3]!=0&&t2!=3){
            cnt[3]--;
            cnt[t2]=t3;
            
        }}
        else if(t1==4){if(cnt[4]!=0&&t2!=4){
            cnt[4]--;
            cnt[t2]+=t3;
            
        }}
        else if(t1==5){if(cnt[5]!=0&&t2!=5&&t3!=5&&t2!=t3){
            cnt[5]--;
            cnt[t3]=cnt[t2];
            
        }}
        else if(t1==6){if(cnt[6]!=0&&t2!=6&&t3!=6&&t2!=t3){
            cnt[6]--;
            cnt[t3]+=cnt[t2];
            cnt[t2]=0;
            
        }}
        for(int j=1;j<7;j++){
            num[i][j]=cnt[j];
        }
    }
    if(cnt[1]!=0&&cnt[2]!=0&&cnt[3]!=0&&cnt[4]!=0&&cnt[5]!=0&&cnt[6]!=0)cout<<"Ciallo~";
    else cout<<"kskbl";
    return 0;
}