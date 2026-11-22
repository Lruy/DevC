#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;cin >> t;
    while(t--) {
        int n;cin >> n;
        vector<int>a(n,0);
        map<int,int>mp;
        int max_num = 0;
        for(int i = 0;i < n;i++)    {
            cin >> a[i];
            mp[a[i]]++;
            max_num = max(max_num,a[i]);
        }
        sort(a.begin(),a.end());
        map<int,int>mex;
        for (int i = 0;i <= max_num + 1;i++) {
            if (mp[i] == 0) {
                mex[0] = i;
                break;
            }
        }
        for(int i = 0;i < n && a[i] <= mex[0];i++) {
            if (mp[a[i]] >= 2) {
                int cnt = 0;
                for (int j = i;j < n && a[j] <= mex[0];j++) {
                    if (mp[a[j]] >= 2) {
                        cnt++;
                    }
                    else break;
                    mex[mex[0] + a[i]] = mex[0] + cnt;
                    mex[mex[0] + a[i]] = mex[0] + 1;
                }
            }
        }
        for (int i = 0;i < n;i++) {
            if (a[i] <= mex[0])    continue;
            if (mp[a[i]] >= 2){
                int cnt = 0;
                int t = a[i] + 1;
                while(t < max_num && mp[t] >= 2) {
                    cnt++;
                    t++;
                }
                mex[mex[0] + a[i]] = mex[0] + cnt;
                mex[mex[0] + a[i]] = mex[0] + 1;
            }
            else if (mp[a[i]] == 1) {
                mex[mex[0] + a[i]] = mex[0] + 1;
            }
        }
        int q;cin >> q;
        int ans = 0;
        while(q--) {
            int aa;cin >> aa;
            ans ^= max(mex[aa],mex[0]);
        }
        cout << ans << '\n';
    }
    return 0;
}