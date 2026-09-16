#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n,k;
ll a[25];
ll ans;
vector<ll> v;
vector<ll> primes;
const ll N=10000;
bool notprime[10005];
void dfs(ll pos,ll cnt,ll sum){
    if(pos>=n||cnt>=k){
        if(cnt==k&&pos<n){
            v.push_back(sum);
            return;
        }
        else return;
    }
    if(n-pos-1<k-cnt)return;
    else{
        dfs(pos+1,cnt+1,sum+a[pos+1]);
        dfs(pos+1,cnt,sum);
    }
}
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
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(-1,0,0);
    for(auto i:v){
        bool isprime=true;
        for(auto p:primes){
            if(p*p>i)break;
            if(i%p==0){isprime=false;break;}
        }
        if(isprime)ans++;
    }
    cout<<ans;
    return 0;
}