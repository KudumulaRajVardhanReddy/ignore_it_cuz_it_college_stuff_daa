#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> keys, freq;

void solve() {
    cin >> n;

    keys.resize(n);
    freq.resize(n);

    for (auto& i : keys) cin >> i;
    for (auto& i : freq) cin >> i;

    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0)), fsum(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = 0; j < n; ++j) {
            current_sum += freq[j];
            fsum[i][j] = current_sum;
        }
    }

    for (int i = 0; i < n; ++i) cost[i][i] = freq[i];

    for (int L = 2; L <= n; ++L) {
        for (int i = 0; i <= n - L; ++i) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r < j; ++r) {
                int left = i < r ? cost[i][r - 1] : 0;
                int right = r < j ? cost[r + 1][j] : 0;
                int current_weight = right + left + fsum[i][j];

                if (current_weight < cost[i][j]) cost[i][j] = current_weight;
            }
        }
    }

    cout << cost[0][n - 1] << "\n";
}

int main() { solve(); }
