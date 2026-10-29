#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> adj(n);
vector<int> path;
vector<bool> visited;

void really_solve(int u) {
    if (path.size() == n) {
        if (adj[u][path[0]]) {
            vector path_copy = path;
            path_copy.push_back(path[0]);

            for (int i = 1; i < path_copy.size(); ++i) {
                cout << path_copy[i] << (i == path_copy.size() - 1 ? "" : " -> ");
            }
            cout << "\n";
        }
        return;
    }

    for (int v = 0; v < n; ++v) {
        if (adj[u][v] && !visited[v]) {
            visited[v] = 1;
            path.push_back(v);

            really_solve(v);

            visited[v] = 0;
            path.pop_back();
        }
    }
}


void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int source = 3;

    visited.assign(n, 0);
    visited[source] = 1;

    path.push_back(source);
    really_solve(source);
}

signed main() { solve(); }
