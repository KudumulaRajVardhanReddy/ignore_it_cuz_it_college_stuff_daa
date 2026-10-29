#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source; cin >> source;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    vector<int> parent(n, -1), dist(n, 2e18);
    dist[source] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, dt]: adj[u]) {
            if (dist[u] + dt < dist[v]) {
                dist[v] = dist[u] + dt;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == 2e18) cout << i << " not reachable";
        else {
            cout << "Node " << i << ": Distance = " << dist[i] << ", Path: ";
            
            vector path{i};
            for (int curr = i; curr != -1; curr = parent[curr]) if (curr != i) path.push_back(curr);
            ranges::reverse(path);
            
            for (int j = 0; j < path.size(); ++j) cout << path[j] << (j == path.size() - 1 ? "" : " -> ");
            cout << "\n";
        }
    }
}

signed main() { solve(); }