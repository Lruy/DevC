#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;

signed main() {
    ll n;
    cin>>n;
    while(n--){
        char ch;
        ch=getchar();
        if(ch=='R'){
            ll r,c;
            scanf("%lldC%lld",&r,&c);
            stack<ll> s;
            while(c){
                s.push(c%26);
                c/=26;
            }
            while(!s.empty()){
                char t='A'-1;
                t+=s.top();
                cout<<t;
            }
            cout<<'\n';
        }
        else{
            ll tmp=ch-'A';
        }
    }
    return 0;
}