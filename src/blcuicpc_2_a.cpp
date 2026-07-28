#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

ll n;
ll a[35][35];
bool vis[35][35];
ll dx[4]={0,0,-1,1};
ll dy[4]={1,-1,0,0};
struct Point{
    ll x,y;
    Point(ll a,ll b){
        x=a;
        y=b;
    }
};

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    queue<Point> q;
    q.push(Point(0,0));
    vis[0][0]=true;
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            ll nx=p.x+dx[i];
            ll ny=p.y+dy[i];
            if(nx>=0&&nx<=n+1&&ny>=0&&ny<=n+1){
                if(!vis[nx][ny]&&!a[nx][ny]){
                    vis[nx][ny]=true;
                    q.push(Point(nx,ny));
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j-1)cout<<" ";
            if(!a[i][j] && !vis[i][j]) cout<<2;
            else cout<<a[i][j];
        }
        cout<<'\n';
    }
    return 0;
}