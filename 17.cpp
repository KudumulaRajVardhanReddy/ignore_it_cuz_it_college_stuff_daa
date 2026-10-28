#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

vector<vector<int>> adj;
vector<bool> vis;

int cnt = 0;

void dfs(int u) {
    vis[u] = 1;
    ++cnt;
    for (auto& v : adj[u]) if (!vis[v]) dfs(v);
}

void solve() {
    int n, m; cin >> n >> m;

    adj.resize(n);
    vis.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (!n) return void(cout << "Graph is connected" << "\n");
    dfs(0);

    cout << "Graph is" << (n != cnt ? " not " : " ") << "connected" << "\n";
}

signed main() { solve(); }
