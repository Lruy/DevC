#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool notprime[200005];
vector<ll> primes;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    notprime[0]=notprime[1]=true;
    for(ll i=2;i<=200000;i++){
        if(!notprime[i])primes.push_back(i);
        for(auto p:primes){
            if(i*p>200000)break;
            notprime[i*p]=true;
        }
    }
    cout<<primes[2024];
    return 0;
}