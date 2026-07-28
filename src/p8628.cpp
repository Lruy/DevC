#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

struct Pos{
    int x,y,step;
    Pos(int a,int b,int c){
        x=a;
        y=b;
        step=c;
    }
};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int ans,n;
int loc[4];
bool vis[105][105];
char mp[105][105];
void bfs(int x,int y,int step){
    queue<Pos> q;
    q.push(Pos(x,y,step));
    vis[x][y]=true;
    while(!q.empty()){
        int xx,yy,ss;
        if(q.front().x==loc[2] &&q.front().y==loc[3]){
            ans=q.front().step;
            break;
        }
        for(int i=0;i<4;i++){
            xx=q.front().x+dx[i];
            yy=q.front().y+dy[i];
            ss=q.front().step+1;
            if(xx>=0 && xx<=n && yy>=0 && yy<=n && !vis[xx][yy] && mp[xx][yy]!=mp[q.front().x][q.front().y]){
                q.push(Pos(xx,yy,ss));
                vis[xx][yy]=true;
            }
        }
        q.pop();
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='A'){
                loc[0]=i;loc[1]=j;
            }
            else if(mp[i][j]=='B'){
                loc[2]=i;loc[3]=j;
            }
        }
    }
    bfs(loc[0],loc[1],0);
    cout<<ans;
    return 0;
}