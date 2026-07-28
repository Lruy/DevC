#include <iostream>
#include <cstring>
using namespace std;

int n[11]={0,1,2,6,24,120,720,5040,40320,362880,3628800};
bool t[11];
long long ans;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    string s;
    cin>>s;
    int len=s.size();
    int c[11];
    for(int i=0;i<len;i++){
        c[i]=s[i]-'a'+1;
    }
    for(int i=0;i<len-1;i++){
        int q=0;
        for(int j=1;j<c[i];j++){
            if(t[j]==true)q++;
        }
        t[c[i]]=true;
        ans+=n[len-i-1]*(c[i]-q-1);
    }
    cout<<ans;
    return 0;
}