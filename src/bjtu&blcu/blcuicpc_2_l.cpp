#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Point{
    ll num,x,y,z;
    Point(){}
}pt[1005];
bool cmp(const Point &a,const Point &b){
    return a.z<b.z;
}
struct Que{
    ll num;
    bool down;
    Que(){}
    Que(ll a,bool b):num(a),down(b){}
};

ll t,n,h,r;
bool u[1005];
bool d[1005];
vector<vector<ll> > v;
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>h>>r;
        v.assign(n,vector<ll>());
        fill(u,u+n,false);
        fill(d,d+n,false);
        for(int i=0;i<n;i++){
            cin>>pt[i].x>>pt[i].y>>pt[i].z;
            pt[i].num=i;
            for(int j=0;j<i;j++){
                ll dx=pt[i].x-pt[j].x,dy=pt[i].y-pt[j].y,dz=pt[i].z-pt[j].z;
                if(dx*dx+dy*dy+dz*dz<=4*r*r){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        sort(pt,pt+n,cmp);
        queue<Que> q;
        for(int i=0;i<n && pt[i].z<=r;i++){
            q.push(Que(pt[i].num,true));
        }
        if(q.empty()){
            cout<<"No\n";
            continue;
        }
        ll tmpsz=q.size();
        for(int i=n-1;i>=0 && pt[i].z>=h-r;i--){
            q.push(Que(pt[i].num,false));
        }
        if(tmpsz==q.size()){
            cout<<"No\n";
            continue;
        }
        bool ans=false;
        while(!q.empty()){
            if(ans)break;
            Que tmp=q.front();
            q.pop();
            if(tmp.down){
                d[tmp.num]=true;
                if(u[tmp.num]){
                    ans=true;
                }
            }
            else{
                u[tmp.num]=true;
                if(d[tmp.num]){
                    ans=true;
                }
            }
            for(auto p:v[tmp.num]){
                if(tmp.down && !d[p]){
                    q.push(Que(p,true));
                }
                else if(!tmp.down && !u[p]){
                    q.push(Que(p,false));
                }
            }
        }
        if(ans)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}