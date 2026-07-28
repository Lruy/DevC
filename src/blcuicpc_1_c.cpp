#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int n,I,h,r;
int mp[10005]={};
set<pair<int,int> > s;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>I>>h>>r;
    while(r--){
        int t1,t2;
        cin>>t1>>t2;
        if(t1>t2)swap(t1,t2);
        s.insert({t1,t2});
    }
    for(auto i:s){
        mp[i.first+1]--;
        mp[i.second]++;
    }
    for(int i=1;i<=n;i++){
        if(i-1)cout<<"\n";
        h+=mp[i];
        cout<<h;
    }
    return 0;
}