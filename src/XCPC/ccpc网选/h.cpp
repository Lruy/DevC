#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[2005][2005];
int cnt[2005][2];
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    ll n;
    cin>>n;
    if(s[0]=='f'){
        for(int i=0;i<n;i++){
            cin>>a[0][i];
            for(int j=1;j<n;j++)a[j][i]=a[0][i];
        }
        for(int i=0;i<n-1;i++){
            swap(a[i][i],a[i][n-1]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j)cout<<" ";
                cout<<a[i][j];
            }
            cout<<'\n';
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tmp;
                cin>>tmp;
                if(tmp==cnt[j][0]){
                    cnt[j][1]++;
                }
                else{
                    if(cnt[j][1]<=0){
                        cnt[j][0]=tmp;
                        cnt[j][1]=1;
                    }
                    else cnt[j][1]--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<cnt[i][0];
        }
    }
    return 0;
}