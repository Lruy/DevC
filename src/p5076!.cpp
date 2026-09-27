#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

multiset<ll> s;
ll cnt=0;
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll q;
    cin>>q;
    while(q--){
        ll op,x;
        cin>>op>>x;
        if(op==1){
            ll tmp=1;
            for(auto it=s.begin();it!=s.end();it++,tmp++){
                if(*it>=x)break;
            }
            cout<<tmp<<'\n';
        }
        else if(op==2){
            for(auto it=s.begin();it!=s.end();it++,x--){
                if(x==1)cout<<*it<<'\n';
            }
        }
        else if(op==3){
            auto it=s.lower_bound(x);
            if(it!=s.begin()){
                it--;
                cout<<*it<<'\n';
            }
            else cout<<"−2147483647"<<'\n';
        }
        else if(op==4){
            auto it=s.lower_bound(x);
            it++;
            if(it!=s.end()){
                cout<<*it<<'\n';
            }
            else cout<<"2147483647"<<'\n';
        }
        else{
            s.insert(x);
            cnt++;
        }
    }
    return 0;
}