#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
#define pqueue priority_queue

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vector<int> dist(n, 2e18);
    dist[0] = 0;

    pqueue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d < dist[u]) continue;

        for (auto& [v, dt]: adj[u]) {
            if (dist[u] + dt < dist[v]) {
                dist[v] = dist[u] + dt;
                pq.push({dist[v], v});
            }
        }
    }

    for (auto& x : dist) cout << (x != 2e18 ? x : -1) << " ";
    cout << "\n";
}

signed main() { solve(); }
