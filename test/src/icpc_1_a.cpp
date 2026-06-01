#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    map<string, int> cnt;
    while (n--)
    {
        string s;
        cin >> s;
        vector<int> pos;
        for (int i = 0; i < s.size(); i++)
        {
            if (isupper(s[i]))
            {
                pos.push_back(i);
            }
        }
        if (pos.size() < 5)
            continue;
        if (s[pos[pos.size() - 1]] == 'Y' && s[pos[pos.size() - 2]] == 'D' && s[pos[pos.size() - 3]] == 'X' && s[pos[pos.size() - 4]] == 'T')
        {
            string name;
            for (int i = 0; i < pos.size() - 4; i++)
            {
                name += s[pos[i]];
            }
            cnt[name]++;
        }
    }
    string ans;
    int maxx = -1;
    for (map<string, int>::iterator p = cnt.begin(); p != cnt.end(); ++p)
    {
        if (p->second > maxx)
        {
            ans = p->first;
            maxx = p->second;
        }
        else if (p->second == maxx && p->first < ans)
            ans = p->first;
    }
    cout << ans << '\n';
    return 0;
}