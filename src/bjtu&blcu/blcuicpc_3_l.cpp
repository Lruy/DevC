#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

ll n,m;
ll rd[1005];
vector<ll> v[1005];
bool used[1005][1005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        vector<ll> t;
        vector<ll> tt;
        ll tmp;
        cin>>tmp;
        ll last;
        cin>>last;
        tt.push_back(last);
        tmp--;
        while(tmp--){
            ll t1;
            cin>>t1;
            tt.push_back(t1);
            for(int i=last+1;i<t1;i++){
                t.push_back(i);
            }
            last=t1;
        }
        for(auto p:tt){
            for(auto pp:t){
                if(used[p][pp]) continue;
                used[p][pp]=1;
                v[p].push_back(pp);
                rd[pp]++;
            }
        }
    }
    queue<ll> q;
    queue<ll> qq;
    for(int i=1;i<=n;i++){
        if(rd[i]==0)q.push(i);
    }
    ll cnt=1;
    while(true){
        while(!q.empty()){
            ll tmp=q.front();
            q.pop();
            for(auto p:v[tmp]){
                rd[p]--;
                if(rd[p]==0)qq.push(p);
            }
        }
        if(qq.empty())break;
        else{
            cnt++;
            q=qq;
            while(!qq.empty())qq.pop();
        }
    }
    cout<<cnt;
    return 0;
}