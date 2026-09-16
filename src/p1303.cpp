#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[4005];
ll b[4005];
ll ans[10005];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string sa,sb;
    cin>>sa>>sb;
    for(int i=0;i<sa.size();i++){
        a[i]=sa[sa.size()-1-i]-'0';
    }
    for(int i=0;i<sb.size();i++){
        b[i]=sb[sb.size()-1-i]-'0';
    }
    for(int i=0;i<sb.size();i++){
        ll tmp[4005]={};
        
    }
    return 0;
}