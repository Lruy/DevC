#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct enemy{
    int x,y,att,hp;
    enemy(int a,int b,int c,int d){x=a;y=b;att=c;hp=d;}
};
struct defender{
    int x,y,att;
    defender(int a,int b,int c){x=a;y=b;att=c;}
};
int n,a,b,p;
vector<enemy> e;
vector<defender> d;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>a>>b>>p;
    for(int i=0;i<a;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        d.push_back(defender(t1,t2,t3));
    }
    for(int i=0;i<b;i++){
        int t1,t2,t3,t4;
        cin>>t1>>t2>>t3>>t4;
        e.push_back(enemy(t1,t2,t3,t4));
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<d.size();j++){
            if(e.empty())break;
            int tx=d[j].x,ty=d[j].y,tatt=d[j].att,lpos=1000,ltar=0;
            for(int k=0;k<e.size();k++){
                int tpos=abs(tx-e[k].x)+abs(ty-e[k].y);
                if(lpos>tpos){lpos=tpos;ltar=k;}
            }
            e[ltar].hp-=tatt;
            if(e[ltar].hp<=0)e.erase(e.begin()+ltar);
        }
        for(int j=0;j<e.size();j++){
            if(e.empty())break;
            if(abs(e[j].x)+abs(e[j].y)<=1)p-=e[j].att;
            else if(e[j].x>=1)e[j].x-=1;
            else if(e[j].x<=-1)e[j].x+=1;
            else if(e[j].y>=1)e[j].y-=1;
            else if(e[j].y<=-1)e[j].y+=1;
        }
        if(e.empty()){
            cout<<"Win\n"<<i<<" "<<p;return 0;
        }
        else if(p<=0){
            cout<<"Lose\n"<<i<<" "<<e.size();return 0;
        }
    }
    cout<<"Draw\n"<<p<<" "<<e.size();
    return 0;
}