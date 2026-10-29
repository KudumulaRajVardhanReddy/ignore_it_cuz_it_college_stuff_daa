#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, 2e18));

    for (int i = 0; i < n; ++i) dist[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (dist[i][k] < 2e18 && dist[k][j] < 2e18) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    for (auto& i : dist) {
        for (auto& j : i) cout << (j == 2e18 ? "INF" : to_string(j)) << " ";
        cout << "\n";
    }
}

signed main() { solve(); }
