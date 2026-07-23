#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 二维差分数组，(n+2) × (m+2)，多开一圈避免边界判断
    vector<vector<ll>> diff(n + 2, vector<ll>(m + 2, 0));

    // 枚举边向量 (dx, dy)
    for (int dx = -n; dx <= n; dx++) {
        for (int dy = -m; dy <= m; dy++) {
            if (dx == 0 && dy == 0) continue;  // 面积为 0，跳过

            // 四个顶点 x 坐标约束: 0≤a≤n, 0≤a+dx≤n, 0≤a+dx-dy≤n, 0≤a-dy≤n
            int a_min = max({0, -dx, dy - dx, dy});
            int a_max = min({n, n - dx, n + dy - dx, n + dy});
            if (a_min > a_max) continue;  // 无合法 a

            // 四个顶点 y 坐标约束: 0≤b≤m, 0≤b+dy≤m, 0≤b+dy+dx≤m, 0≤b+dx≤m
            int b_min = max({0, -dy, -dy - dx, -dx});
            int b_max = min({m, m - dy, m - dy - dx, m - dx});
            if (b_min > b_max) continue;  // 无合法 b

            // O(1) 二维差分区间加
            diff[a_min][b_min]++;
            diff[a_min][b_max + 1]--;
            diff[a_max + 1][b_min]--;
            diff[a_max + 1][b_max + 1]++;
        }
    }

    // 二维前缀和还原，同时输出
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0) diff[i][j] += diff[i - 1][j];
            if (j > 0) diff[i][j] += diff[i][j - 1];
            if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];
            if (j > 0) cout << ' ';
            cout << diff[i][j];
        }
        cout << '\n';
    }

    return 0;
}
