#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
typedef long long ll;

bool e=false;
bitset<200000000> a;
ll idx=0;
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(!e){
        string s;
        cin>>s;
        ll len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='E'){
                e=true;
                break;
            }
            else{
                if(s[i]=='W'){
                    a[idx]=1;
                    idx++;
                }
                else idx++;
            }
        }
    }
    int W=0,L=0;
    for(int i=0;i<idx;i++){
        if(a[i])W++;
        else L++;
        if(W>=11 && W-L>=2){
            cout<<W<<":"<<L<<'\n';
            W=0;L=0;
        }
        else if(L>=11 && L-W>=2){
            cout<<W<<":"<<L<<'\n';
            W=0;L=0;
        }
    }
    cout<<W<<":"<<L<<'\n';
    W=0;L=0;
    cout<<'\n';
    for(int i=0;i<idx;i++){
        if(a[i])W++;
        else L++;
        if(W>=21 && W-L>=2){
            cout<<W<<":"<<L<<'\n';
            W=0;L=0;
        }
        else if(L>=21 && L-W>=2){
            cout<<W<<":"<<L<<'\n';
            W=0;L=0;
        }
    }
    cout<<W<<":"<<L<<'\n';
    return 0;
}