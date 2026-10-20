#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

map<ll,ll> mp;
map<ll,ll> mp2;
signed main() {
    for(int i=0;i<8;i++)getchar();
    char ch;
    ll tmp=0;
    ll idx=1;
    while(true){
        ch=getchar();
        if(ch>='0'&&ch<='9')tmp=(tmp<<3)+(tmp<<1)+(ch-'0');
        else if(ch==','){
            //cout<<tmp<<endl;
            if(mp[tmp]==0)mp[tmp]=idx;
            else mp2[tmp]=idx;
            idx++;
            tmp=0;
        }
        else if(ch==']'){
            //cout<<tmp<<endl;

            tmp=0;
            break;
        }
    }
    ll tar;
    scanf(", target = %lld",&tar);
    //cout<<tar<<endl;
    for(auto p:mp){
        if(p.first*2!=tar){
            if(mp[tar-p.first]!=0&&p.second!=mp[tar-p.first]){
                cout<<"["<<min(p.second-1,mp[tar-p.first]-1)<<","<<max(p.second-1,mp[tar-p.first]-1)<<"]";
                break;
            }
        }
        else{
            if(mp2[tar-p.first]!=0){
                cout<<"["<<min(p.second-1,mp2[tar-p.first]-1)<<","<<max(p.second-1,mp2[tar-p.first]-1)<<"]"; 
                break;
            }
        }
    }
    return 0;
}