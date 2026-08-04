#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

ll n;
ll rd[105];
vector<vector<ll> > v(105);
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll tmp;
        cin>>tmp;
        while(tmp!=0){
            v[i].push_back(tmp);
            rd[tmp]++;
            cin>>tmp;
        }
    }
    queue<ll> q;
    for(int i=1;i<=n;i++){
        if(rd[i]==0)q.push(i);
    }
    bool first=true;
    while(!q.empty()){
        ll tmp=q.front();
        q.pop();
        if(!first)cout<<" ";
        first=false;
        cout<<tmp;
        for(auto p:v[tmp]){
            rd[p]--;
            if(rd[p]==0){
                q.push(p);
            }
        }
    }
    return 0;
}