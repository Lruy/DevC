#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n,m;
struct edge{
    int from,to,len;
    edge(int a,int b,int c){from=a;to=b;len=c;}
    friend bool operator<(edge a,edge b){return a.len<b.len;}
};
vector<edge> mp;
vector<int> fat(100005,-1);
int find(int x){
    if(fat[x]<0)return x;
    else return fat[x]=find(fat[x]);
}
void uni(int x,int y){
    int rootx=find(x);
    int rooty=find(y);
    if(rootx!=rooty){
        if(rootx<rooty){fat[rootx]+=fat[rooty];fat[rooty]=rootx;}
        else {fat[rooty]+=fat[rootx];fat[rootx]=rooty;}
    }
};
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        mp.push_back(edge(t1,t2,t3));
    }
    sort(mp.begin(),mp.end());
    int cnt=0;
    int ans=0;
    for(int i=0;i<mp.size() && cnt<=n-1;i++){
        if(find(mp[i].from)!=find(mp[i].to)){
            uni(mp[i].from,mp[i].to);
            cnt++;
            ans+=mp[i].len;
        }
    }
    cout<<ans;
    return 0;
}