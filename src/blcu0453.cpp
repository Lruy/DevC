#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

ll n,mmax,sum;
vector<pair<string,ll> > v;
string s;
ll sc1,sc2;
char b1,b2;
ll pp;
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        ll tmp=0;
        cin>>s>>sc1>>sc2>>b1>>b2>>pp;
        if(sc1>80&&pp>=1)tmp+=8000;
        if(sc1>85&&sc2>80)tmp+=4000;
        if(sc1>90)tmp+=2000;
        if(sc1>85&&b2=='Y')tmp+=1000;
        if(sc2>80&&b1=='Y')tmp+=850;
        if(tmp>mmax){
            mmax=tmp;
            v.clear();
        }
        if(tmp==mmax){
            v.push_back(make_pair(s,tmp));
        }
        sum+=tmp;
    }
    for(auto p:v)cout<<p.first<<'\n'<<p.second<<'\n';
    cout<<sum;
    return 0;
}