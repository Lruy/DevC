#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b, n, m;
    while (scanf("%d %d %d %d", &a, &b, &n, &m) == 4)
    {
        if (a < 1 || b < 1 || n < 1 || m < 1)
        {
            printf("Invalid Arguments\n");
            continue;
        }
        set<int> ans;
        int num = n;
        while (ans.size() < m)
        {
            if (num % a == 0 || num % b == 0)
            {
                ans.insert(num);
            }
            num++;
        }
        bool space = false;
        for (int x : ans)
        {
            if (space)
                printf(" ");
            printf("%d", x);
            space = true;
        }
        printf("\n");
    };
    return 0;
}