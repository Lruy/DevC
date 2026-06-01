#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    string s;
    int casenum = 1;
    while(getline(cin,s)){
        stringstream ss(s);
        int a;
        vector<int> b;
        while(ss >> a){
            b.push_back(a);
        }
        int maxlen = -1;
        vector<vector<int>> plat;
        for(int i=0;i<b.size();i++){
            int fromwhere = i+1;
            int len = 0;
            for(int j=i;b[i]==b[j] && j<b.size();j++){
                len++;
            }
            plat.push_back({b[i],fromwhere,len});
            if(len>maxlen)maxlen=len;
        }
        cout << "Case " << casenum << ":\n";
        casenum++;
        for(auto &p : plat){
            if(p[2] == maxlen){
                cout << p[0] << ":" << p[1] << "-" << p[2] << '\n';
            }
        }
    }
    return 0;
}