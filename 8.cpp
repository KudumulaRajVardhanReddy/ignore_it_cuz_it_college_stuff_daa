#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, W, max_profit = 0;
vector<int> val, wt;
vector<bool> current_picked, best_picked;

void backtrack(int index, int current_weight, int current_profit) {
    if (index == n) {
        if (current_profit > max_profit) {
            max_profit = current_profit;
            best_picked = current_picked;
        }
        return;
    }

    if (current_weight + wt[index] <= W) {
        current_picked[index] = 1;
        backtrack(index + 1, current_weight + wt[index], current_profit + val[index]);
    }

    current_picked[index] = 0;
    backtrack(index + 1, current_weight, current_profit);
}

void solve() {
    cin >> n >> W;

    val.resize(n);
    wt.resize(n);

    current_picked.assign(n, 0);
    best_picked.assign(n, 0);

    for (auto& i : val) cin >> i;
    for (auto& i : wt) cin >> i;

    backtrack(0, 0, 0);

    for (auto i : best_picked) cout << (i ? 1 : 0) << " ";
    cout << "\n";
}

signed main() { solve(); }
