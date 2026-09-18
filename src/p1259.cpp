#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll n;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    string s="";
    s.insert(0,n,'o');
    s.insert(n,n,'*');
    s.insert(2*n,2,'-');
    cout<<s<<'\n';
    for(int i=n-1;i>=4;i--){
        s[i]='-';
        s[i+1]='-';
        s[2*n-2*(n-1-i)]='o';
        s[2*n-2*(n-1-i)+1]='*';
        cout<<s<<'\n';
        s[i]='*';
        s[i+1]='*';
        s[2*n-2*(n-1-i)-2]='-';
        s[2*n-2*(n-1-i)-1]='-';
        if(i)cout<<s<<'\n';
    }
    s[0]='o';s[1]='o';s[2]='o';s[3]='-';s[4]='-';s[5]='*';s[6]='*';s[7]='*';s[8]='o';s[9]='*';cout<<s<<'\n';
    s[0]='o';s[1]='o';s[2]='o';s[3]='*';s[4]='o';s[5]='*';s[6]='*';s[7]='-';s[8]='-';s[9]='*';cout<<s<<'\n';
    s[0]='o';s[1]='-';s[2]='-';s[3]='*';s[4]='o';s[5]='*';s[6]='*';s[7]='o';s[8]='o';s[9]='*';cout<<s<<'\n';
    s[0]='o';s[1]='*';s[2]='o';s[3]='*';s[4]='o';s[5]='*';s[6]='-';s[7]='-';s[8]='o';s[9]='*';cout<<s<<'\n';
    s[0]='-';s[1]='-';s[2]='o';s[3]='*';s[4]='o';s[5]='*';s[6]='o';s[7]='*';s[8]='o';s[9]='*';cout<<s<<'\n';
    return 0;
}
/*
oooo****--o*o*o*
ooo--***o*o*o*o*
ooo*o**--*o*o*o*
o--*o**oo*o*o*o*
o*o*o*--o*o*o*o*
--o*o*o*o*o*o*o*

oooo****--o*o*o*
ooo--***o*o*o*o*
ooo*o**--*o*o*o*
o--*o**oo*o*o*o*
o*o*o*--o*o*o*o*
--o*o*o*o*o*o*o*

oooo****--o*o*o*
ooo--***o*o*o*o*
ooo***--o*o*o*o*
oo--**o*o*o*o*o*
oo**--o*o*o*o*o*
o--*o*o*o*o*o*o*
o*--o*o*o*o*o*o*
--o*o*o*o*o*o*o*
*/