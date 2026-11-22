#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
typedef int ll;
struct Que{
    ll x,y;
    ll depth;
    Que(){}
    Que(ll a,ll b,ll c):x(a),y(b),depth(c){};
};
ll dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
ll n,m,r;
char mp[1005][1005];
ll cnt[1005][1005];
vector<pair<ll,ll> > e;
bool vis[1005][1005][11];
pair<ll,ll> npos;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>r;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='P')e.push_back(make_pair(i,j));
            if(mp[i][j]=='N')npos=make_pair(i,j);
        }
    }
    ll ecnt=e.size();
    queue<Que> q;
    for(int k=0;k<ecnt;k++){
        pair<ll,ll> p=e[k];
        q.push(Que(p.first,p.second,0));
        while(!q.empty()){
            Que tmp=q.front();
            q.pop();
            if(tmp.depth>r)continue;
            vis[tmp.x][tmp.y][k]=true;
            cnt[tmp.x][tmp.y]++;
            for(int i=0;i<4;i++){
                if(!vis[tmp.x+dx[i]][tmp.y+dy[i]][k]&&mp[tmp.x+dx[i]][tmp.y+dy[i]]!='#'&&tmp.x+dx[i]>=0&&tmp.x+dx[i]<n&&tmp.y+dy[i]>=0&&tmp.y+dy[i]<m){
                    q.push(Que(tmp.x+dx[i],tmp.y+dy[i],tmp.depth+1));
                    vis[tmp.x+dx[i]][tmp.y+dy[i]][k]=true;
                }
            }
        }
    }
    q.push(Que(npos.first,npos.second,0));
    bool findd=false;
    ll ans=-1;
    
    while(!q.empty()){
        Que tmp=q.front();
        q.pop();
        if(findd)continue;
        if(cnt[tmp.x][tmp.y]==ecnt){
            findd=true;
            ans=tmp.depth;
        }
        vis[tmp.x][tmp.y][10]=true;
        for(int i=0;i<4;i++){
            if(!vis[tmp.x+dx[i]][tmp.y+dy[i]][10]&&mp[tmp.x+dx[i]][tmp.y+dy[i]]!='#'&&tmp.x+dx[i]>=0&&tmp.x+dx[i]<n&&tmp.y+dy[i]>=0&&tmp.y+dy[i]<m){
                q.push(Que(tmp.x+dx[i],tmp.y+dy[i],tmp.depth+1));
                vis[tmp.x+dx[i]][tmp.y+dy[i]][10]=true;
            }
        }
    }
    cout<<ans;
    return 0;
}