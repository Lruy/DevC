#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    stack<ll> stk;
    int cnt=-1;
    string tmp="";
    do{
        for(int j=0;j<s.size();j++){
            if(s[j]=='[')stk.push(j);
            if(s[j]==']'){
                if(!(s[stk.top()+2]>='0'&& s[stk.top()+2]<='9')){
                    char ttmp=s[stk.top()+1];
                    cnt=ttmp-'0';
                    tmp=s.substr(stk.top()+2,j-stk.top()-2);
                }
                else{
                    char ttmp=s[stk.top()+1];
                    char tttp=s[stk.top()+2];
                    cnt=(ttmp-'0')*10+(tttp-'0');
                    tmp=s.substr(stk.top()+3,j-stk.top()-3);
                }
                s.erase(stk.top(),j-stk.top()+1);
                j=stk.top();
                for(int k=0;k<cnt;k++)s.insert(stk.top(),tmp);
                j+=tmp.size()*cnt-1;
                stk.pop();
            }
        }
    }while(!stk.empty());
    cout<<s;
    return 0;
}