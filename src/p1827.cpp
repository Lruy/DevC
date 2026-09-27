#include <iostream>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;

struct Node{
    char ch;
    ll lson,rson;
}tree[205];
map<char,ll> mp;
void dfs(ll root,bool isleft,string mid,string fro){
    if(mid.length()==0)return;
    else if(mid.length()==1){
        if(isleft)tree[root].lson=mp[fro[0]];
        else tree[root].rson=mp[fro[0]];
    }
    char tmp=fro[0];
    for(int i=0;i<mid.size();i++){
        if(mid[i]==tmp){
            dfs(mp[mid[i]],true,mid.substr(0,i),fro.substr(1,i));
            dfs(mp[mid[i]],false,mid.substr(i+1,100),fro.substr(i+1,100));
            if(isleft)tree[root].lson=mp[fro[0]];
            else tree[root].rson=mp[fro[0]];
            return;
        }
    }
}
void back(ll root){
    if(tree[root].lson!=0){
        back(tree[root].lson);
    }
    if(tree[root].rson!=0){
        back(tree[root].rson);
    }
    cout<<tree[root].ch;
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string mid,fro;
    cin>>mid>>fro;
    ll idx=1;
    for(int i=0;i<fro.length();i++){mp[fro[i]]=idx;tree[idx].ch=fro[i];idx++;}
    for(int i=0;i<mid.size();i++){
        if(mid[i]==fro[0]){
            dfs(1,true,mid.substr(0,i),fro.substr(1,i));
            dfs(1,false,mid.substr(i+1,100),fro.substr(i+1,100));
            break;
        }
    }
    back(1);
    return 0;
}