#include <iostream>
using namespace std;
typedef long long ll;

ll t;
ll a[200005][3];
bool str[200005];
int cntt[200005];
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=0;i<=2;i++){
            for(int j=0;j<n;j++){
                cin>>a[j][i];
            }
        }
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(cntt[a[i][0]]==1){
                cntt[a[i][0]]=0;
                cnt--;
            }
            else{
                cntt[a[i][0]]=1;
                cnt++;
            }
            if(cntt[a[i][1]]==1){
                cnt--;
                cntt[a[i][1]]=0;
            }
            else{
                cntt[a[i][1]]=1;
                cnt++;
            }
            if(cnt==0){
                str[i]=true;
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(cntt[a[i][0]]==1){
                cntt[a[i][0]]=0;
                cnt--;
            }
            else{
                cntt[a[i][0]]=1;
                cnt++;
            }
            if(cntt[a[i][2]]==1){
                cnt--;
                cntt[a[i][2]]=0;
            }
            else{
                cntt[a[i][2]]=1;
                cnt++;
            }
            if(cnt==0){
                str[i]=true;
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(cntt[a[i][2]]==1){
                cntt[a[i][2]]=0;
                cnt--;
            }
            else{
                cntt[a[i][2]]=1;
                cnt++;
            }
            if(cntt[a[i][1]]==1){
                cnt--;
                cntt[a[i][1]]=0;
            }
            else{
                cntt[a[i][1]]=1;
                cnt++;
            }
            if(cnt==0){
                str[i]=true;
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(str[i]){cnt++;str[i]=false;}
        }
        cout<<cnt<<'\n';
    }
    return 0;
}