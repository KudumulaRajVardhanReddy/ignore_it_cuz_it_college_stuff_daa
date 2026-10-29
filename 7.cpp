#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, W; cin >> n >> W;

    vector<int> val(n), wt(n), dp(W + 1, 0), taken;
    vector<vector<bool>> picked(W + 1, vector<bool>(n, 0));

    for (int i = 0; i < n; ++i) cin >> val[i] >> wt[i];

    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= wt[i]; --w) {
            if (dp[w - wt[i]] + val[i] > dp[w]) {
                dp[w] = dp[w - wt[i]] + val[i];
                picked[w] = picked[w - wt[i]];
                picked[w][i] = 1;
            }
        }
    }

    cout << dp[W] << "\n";

    for (int i = 0; i < n; ++i) if (picked[W][i]) taken.push_back(i);
    for (auto& i : taken) cout << i << " ";
    cout << "\n";
}

signed main() { solve(); }
