#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll n;
string s[15];
bool is[15];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    s[0]="2(0)";
    s[1]="2";
    s[2]="2(2)";
    s[3]="2(2+2(0))";
    s[4]="2(2(2))";
    s[5]="2(2(2)+2(0))";
    s[6]="2(2(2)+2)";
    s[7]="2(2(2)+2+2(0))";
    s[8]="2(2(2+2(0)))";
    s[9]="2(2(2+2(0))+2(0))";
    s[10]="2(2(2+2(0))+2)";
    s[11]="2(2(2+2(0))+2+2(0))";
    s[12]="2(2(2+2(0))+2(2))";
    s[13]="2(2(2+2(0))+2(2)+2(0))";
    s[14]="2(2(2+2(0))+2(2)+2)";
    for(int i=0;n;i++){
        if(n&1)is[i]=true;
        n>>=1;
    }
    bool first=true;
    for(int i=14;i>=0;i--){
        if(is[i]){
            if(!first)cout<<"+";
            first=false;
            cout<<s[i];
        }
    }
    return 0;
}
/*
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
*/