#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> primes;
const ll N=10000;
bool notprime[N+5];

signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    notprime[0]=true;
    notprime[1]=true;
    for(int i=2;i<=N;i++){
        if(!notprime[i])primes.push_back(i);
        for(auto p:primes){
            if(1LL*p*i>N)break;
            notprime[i*p]=true;
            if(i%p==0)break;
        }
    }
    
    return 0;
}