#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, min_tour_cost;
vector<vector<int>> dist;
vector<bool> visited;
vector<int> best_path, curr_path;

void backtrack(int u, int count, int current_cost) {
    if (current_cost >= min_tour_cost) return;

    if (count == n) {
        int total_cost = current_cost + dist[u][0];
        if (total_cost < min_tour_cost) {
            min_tour_cost = total_cost;
            best_path = curr_path;
        }
        return;
    }

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            visited[v] = 1;
            curr_path.push_back(v);

            backtrack(v, count + 1, current_cost + dist[u][v]);

            visited[v] = 0;
            curr_path.pop_back();
        }
    }
}

void solve() {
    cin >> n;

    dist.assign(n, vector<int>(n));
    for (auto& i : dist) for (auto& j : i) cin >> j;

    visited.assign(n, 0);
    if (n > 0) visited[0] = 1;

    best_path.clear();
    curr_path.clear();
    curr_path.push_back(0);

    min_tour_cost = LLONG_MAX;

    backtrack(0, 1, 0);

    for (auto& i : best_path) cout << i << " -> ";
    cout << "0\n";
}

signed main() { solve(); }