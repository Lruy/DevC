#include <iostream>
#include <vector>
using namespace std;

int n,ans;
vector<int> a;
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=29;i>=0;i--){
        int cand=ans|(1<<i);
        int sz=a.size();
        int cnt=0;
        for(int j=0;j<sz;j++){
            if((a[j]&cand)==cand)cnt++;
        }
        if(cnt>=2)ans=cand;
    }
    cout<<ans;
    return 0;
}