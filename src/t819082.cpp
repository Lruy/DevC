#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

ll mar[35][35];
ll cnt[35][35][2];
pair<ll,ll> ans;
ll anss=0;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>mar[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            ll t1=0,t2=0,t3=0;
            if(mar[i-1][j]==1)t1++;
            else if(mar[i-1][j]==2)t2++;
            else if(mar[i-1][j]==3)t3++;
            if(mar[i][j-1]==1)t1++;
            else if(mar[i][j-1]==2)t2++;
            else if(mar[i][j-1]==3)t3++;
            if(mar[i+1][j]==1)t1++;
            else if(mar[i+1][j]==2)t2++;
            else if(mar[i+1][j]==3)t3++;
            if(mar[i][j+1]==1)t1++;
            else if(mar[i][j+1]==2)t2++;
            else if(mar[i][j+1]==3)t3++;
            if(mar[i][j]==1){
                anss+=t1;
                if(t2>=t3){cnt[i][j][0]=t2;cnt[i][j][1]=t1;}
                else {cnt[i][j][0]=t3;cnt[i][j][1]=t1;}
            }
            else if(mar[i][j]==2){
                anss+=t2;
                if(t1>=t3){cnt[i][j][0]=t1;cnt[i][j][1]=t2;}
                else {cnt[i][j][0]=t3;cnt[i][j][1]=t2;}
            }
            else if(mar[i][j]==3){
                anss+=t3;
                if(t1>=t2){cnt[i][j][0]=t1;cnt[i][j][1]=t3;}
                else {cnt[i][j][0]=t2;cnt[i][j][1]=t3;}
            }
            if(cnt[i][j][0]-cnt[i][j][1]>cnt[ans.first][ans.second][0]-cnt[ans.first][ans.second][1]){
                ans.first=i;
                ans.second=j;
            }
        }
    }
    anss/=2;
    anss-=cnt[ans.first][ans.second][1];
    anss+=cnt[ans.first][ans.second][0];
    cout<<anss;
    return 0;
}