#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<vector<int>> dist, memo, nxt;

int tsp(int mask, int u) {
    if (mask == (1LL << n) - 1) return dist[u][0];

    if (memo[mask][u] != -1) return memo[mask][u];

    int ans = LLONG_MAX, best_next_city = -1;

    for (int v = 0; v < n; ++v) {
        if (!(mask & (1LL << v))) {
            int current_cost = dist[u][v] + tsp(mask | (1LL << v), v);
            if (current_cost < ans) {
                ans = current_cost;
                best_next_city = v;
            }
        }
    }

    nxt[mask][u] = best_next_city;
    return memo[mask][u] = ans;
}

void solve() {
    if (!(cin >> n)) return;

    dist.assign(n, vector<int>(n));
    for (auto& i : dist) for (auto& j : i) cin >> j;

    memo.assign(1LL << n, vector<int>(n, -1));
    nxt.assign(1LL << n, vector<int>(n, -1));

    int min_tour_cost = tsp(1LL, 0);
    int current_mask = 1LL, current_city = 0;

    cout << current_city;
    while (true) {
        int next_node = nxt[current_mask][current_city];
        if (next_node == -1) break;
        
        cout << " -> " << next_node;
        current_mask |= (1LL << next_node);
        current_city = next_node;
    }
    cout << " -> 0\n";
}

signed main() { solve(); }
