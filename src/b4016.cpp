#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

struct que{
    int pos,fat,len;
    que(int a=0,int b=0,int c=0){
        pos=a;fat=b;len=c;
    }
};
int n;
que m;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    vector<vector<int> > v(n+5);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<que> q;
    q.push(que(1,-1,0));
    while(!q.empty()){
        if(q.front().len>m.len){
            m.pos=q.front().pos;
            m.len=q.front().len;
        }
        for(int i=0;i<v[q.front().pos].size();i++){
            if(v[q.front().pos][i]!=q.front().fat){
                q.push(que(v[q.front().pos][i],q.front().pos,q.front().len+1));
            }
        }
        q.pop();
    }
    que m2;
    q.push(que(m.pos,-1,0));
    while(!q.empty()){
        if(q.front().len>m2.len){
            m2.len=q.front().len;
        }
        for(int i=0;i<v[q.front().pos].size();i++){
            if(v[q.front().pos][i]!=q.front().fat){
                q.push(que(v[q.front().pos][i],q.front().pos,q.front().len+1));
            }
        }
        q.pop();
    }
    cout<<m2.len;
    return 0;
}