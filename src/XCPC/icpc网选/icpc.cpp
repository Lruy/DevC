#include<iostream>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
map<string,ll> mp;
ll n,p;
void solve(){
    cin>>n>>p;
    ll sum=0;
    string s;
    for(ll i=0;i<n;i++){
        cin>>s;
        if(s[s.size()-1]<='z'&&s[s.size()-1]>='a'){
            sum+=mp[s];
        }
        else{
            string k=s.substr(0,s.size()-1);
            sum+=mp[k];
        }
    }
    if(sum>p) cout<<"Joker"<<'\n';
    else cout<<"Judger"<<'\n';
    
}
int main(){
    ll t;
    cin>>t;
    mp["WrongProblem"]=100;
    mp["SameProblem"]=30;
    mp["UnreasonableProblemArrangement"]=10;
    mp["UnreasonableLimitForProblem"]=5;
    mp["WeakTestForProblem"]=3;
    mp["BadProblem"]=0;
    while(t--) solve();
    return 0;
}


