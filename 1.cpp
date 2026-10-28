#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>
#define pqueue priority_queue

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    pqueue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    int cost = 0, cnt = 0;
    vector<bool> vis(n, 0);

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        cost += w;
        ++cnt;

        for (auto& [v, wt]: adj[u]) if (!vis[v]) pq.push({wt, v});
    }

    cout << (cnt < n ? -1 : cost) << "\n";
}

signed main() { solve(); }
