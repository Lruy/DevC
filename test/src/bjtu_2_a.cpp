#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int> > mp(100005);
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<": {";
        bool first=true;
        for(int j=0;j<mp[i].size();j++){
            if(!first)cout<<", ";
            first=false;
            cout<<mp[i][j];
        }
        cout<<"}"<<'\n';
    }
    return 0;
}