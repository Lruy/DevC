    #include <iostream>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    typedef long long ll;

    struct Bigint{
        int a[5005];
        int strlen;
        Bigint(){
            strlen=0;
        }
        Bigint(ll aa,int bb):strlen(bb){
            memset(a,0,sizeof(a));
            for(int i=0;i<bb;i++){
                this->a[i]=aa%10;
                aa/=10;
            }
        }
        Bigint operator+(Bigint &other){
            Bigint ans(0,1);
            int add=0;
            int len=max(this->strlen,other.strlen);
            for(int i=0;i<len;i++){
                int tmp=this->a[i]+other.a[i]+add;
                ans.a[i]=tmp%10;
                add=tmp/10;
            }
            if(add){
                ans.a[len]=add;
                len++;
            }
            ans.strlen=len;
            return ans;
        }
    };


    ll x1,y1,x2,y2;
    Bigint dp[25][25];
    bool mp[25][25];
    ll dx[8]={-2,-1,1,2,2,1,-1,-2};
    ll dy[8]={1,2,2,1,-1,-2,-2,-1};
    int main() {
        ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
        cin>>x1>>y1>>x2>>y2;
        mp[x2][y2]=true;
        for(int i=0;i<8;i++){
            if(x2+dx[i]>=0 && y2+dy[i]>=0)mp[x2+dx[i]][y2+dy[i]]=true;
        }
        dp[0][0].strlen=1;
        dp[0][0].a[0]=1;
        bool block=false;
        for(int i=1;i<=y1;i++){
            if(mp[0][i]){block=true;break;}
            if(!block){dp[0][i].a[0]=1;dp[0][i].strlen=1;}
        }
        block=false;
        for(int i=1;i<=x1;i++){
            if(mp[i][0]){block=true;break;}
            if(!block){dp[i][0].a[0]=1;dp[i][0].strlen=1;}
        }
        for(int i=1;i<=x1;i++){
            for(int j=1;j<=y1;j++){
                if(!mp[i][j]){
                    if(!mp[i-1][j])dp[i][j]=dp[i-1][j]+dp[i][j];
                    if(!mp[i][j-1])dp[i][j]=dp[i][j]+dp[i][j-1];
                }
            }
        }
        if(dp[x1][y1].strlen!=0){
            for(int i=dp[x1][y1].strlen-1;i>=0;i--){
                if(i!=dp[x1][y1].strlen-1||dp[x1][y1].a[i])cout<<dp[x1][y1].a[i];
            }
        }
        else{
            cout<<0;
        }
        return 0;
    }