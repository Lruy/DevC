#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n;
    string s;
    cin>>n;
    cin>>s;
    bool first=true;
    for(int i=0;i<n;i++){
        if(first){
            if(s[i]=='0');
            else if(s[i]=='1')cout<<"1";
            else if(s[i]=='2')cout<<"10";
            else if(s[i]=='3')cout<<"11";
            else if(s[i]=='4')cout<<"100";
            else if(s[i]=='5')cout<<"101";
            else if(s[i]=='6')cout<<"110";
            else if(s[i]=='7')cout<<"111";
            else if(s[i]=='8')cout<<"1000";
            else if(s[i]=='9')cout<<"1001";
            else if(s[i]=='A')cout<<"1010";
            else if(s[i]=='B')cout<<"1011";
            else if(s[i]=='C')cout<<"1100";
            else if(s[i]=='D')cout<<"1101";
            else if(s[i]=='E')cout<<"1110";
            else if(s[i]=='F')cout<<"1111";
        }
        else{
            if(s[i]=='0')cout<<"0000";
            else if(s[i]=='1')cout<<"0001";
            else if(s[i]=='2')cout<<"0010";
            else if(s[i]=='3')cout<<"0011";
            else if(s[i]=='4')cout<<"0100";
            else if(s[i]=='5')cout<<"0101";
            else if(s[i]=='6')cout<<"0110";
            else if(s[i]=='7')cout<<"0111";
            else if(s[i]=='8')cout<<"1000";
            else if(s[i]=='9')cout<<"1001";
            else if(s[i]=='A')cout<<"1010";
            else if(s[i]=='B')cout<<"1011";
            else if(s[i]=='C')cout<<"1100";
            else if(s[i]=='D')cout<<"1101";
            else if(s[i]=='E')cout<<"1110";
            else if(s[i]=='F')cout<<"1111";
        }
        first=false;
    }
    return 0;
}