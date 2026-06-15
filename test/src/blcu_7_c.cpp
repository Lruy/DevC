#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 读入图
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int deg;
        cin >> deg;
        g[i].resize(deg);
        for (int j = 0; j < deg; j++) cin >> g[i][j];
    }

    // ===== 迭代版 Tarjan 求 SCC（避免递归爆栈）=====
    vector<int> dfn(n + 1), low(n + 1), scc_id(n + 1);
    vector<int> stk;
    vector<bool> instk(n + 1);
    vector<int> it(n + 1, 0);
    vector<int> dfs_stack;
    int timer = 0, scc_cnt = 0;

    for (int start = 1; start <= n; start++) {
        if (dfn[start]) continue;

        dfs_stack.push_back(start);
        dfn[start] = low[start] = ++timer;
        stk.push_back(start);
        instk[start] = true;

        while (!dfs_stack.empty()) {
            int u = dfs_stack.back();

            if (it[u] < (int)g[u].size()) {
                int v = g[u][it[u]++];
                if (!dfn[v]) {
                    dfn[v] = low[v] = ++timer;
                    stk.push_back(v);
                    instk[v] = true;
                    dfs_stack.push_back(v);
                } else if (instk[v]) {
                    low[u] = min(low[u], dfn[v]);
                }
            } else {
                // u 的所有邻居处理完毕，回溯
                dfs_stack.pop_back();
                if (!dfs_stack.empty()) {
                    int p = dfs_stack.back();
                    low[p] = min(low[p], low[u]);
                }
                if (dfn[u] == low[u]) {  // u 是 SCC 根
                    scc_cnt++;
                    int x;
                    do {
                        x = stk.back();
                        stk.pop_back();
                        instk[x] = false;
                        scc_id[x] = scc_cnt;
                    } while (x != u);
                }
            }
        }
    }

    // ===== 统计每个 SCC 的信息 =====
    vector<vector<int>> scc_nodes(scc_cnt + 1);
    vector<int> scc_size(scc_cnt + 1, 0);
    vector<ll> scc_sum_a(scc_cnt + 1, 0);
    vector<bool> scc_self_loop(scc_cnt + 1, false);

    for (int i = 1; i <= n; i++) {
        int sid = scc_id[i];
        scc_nodes[sid].push_back(i);
        scc_size[sid]++;
        scc_sum_a[sid] += a[i];
    }

    // 检查自环
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (u == v) scc_self_loop[scc_id[u]] = true;
        }
    }

    // ===== 沿拓扑序传播 "激活" 和 "无限" 状态 =====
    // Tarjan 的 SCC 编号是逆拓扑序：编号越大越是"源"，编号越小越是"汇"
    // 所以从 scc_cnt 到 1 遍历就是拓扑序（源→汇）
    vector<bool> activated(scc_cnt + 1, false);
    vector<bool> infinite(scc_cnt + 1, false);

    for (int i = scc_cnt; i >= 1; i--) {
        int u = i;

        // 内部有初始能量则激活
        if (scc_sum_a[u] > 0) activated[u] = true;

        // 激活 + 非平凡 SCC → 会产生无限循环
        bool non_trivial = (scc_size[u] > 1) || scc_self_loop[u];
        if (activated[u] && non_trivial) {
            infinite[u] = true;
        }

        // 把状态沿原图的边传播给后继 SCC
        if (activated[u] || infinite[u]) {
            for (int node : scc_nodes[u]) {
                for (int v : g[node]) {
                    int sv = scc_id[v];
                    if (sv != u) {  // 不同 SCC 之间的边（DAG 边）
                        if (activated[u]) activated[sv] = true;
                        if (infinite[u]) infinite[sv] = true;
                    }
                }
            }
        }
    }

    // ===== 答案 = 所有 infinite 的 SCC 的大小之和 =====
    ll ans = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (infinite[i]) ans += scc_size[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
