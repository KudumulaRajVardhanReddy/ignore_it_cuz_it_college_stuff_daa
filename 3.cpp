#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, solutions_count = 0;
vector<int> queen_positions;

void print_board() {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) cout << (queen_positions[r] == c ? "Q " : ". ");
        cout << "\n";
    }
    cout << "\n\n";
}

void backtrack(int row, int cols, int diag1, int diag2) {
    if (row == n) {
        ++solutions_count;
        print_board();
        return;
    }

    int available_slots = ((1 << n) - 1) & ~(cols | diag1 | diag2);

    while (available_slots > 0) {
        int p = available_slots & -available_slots;
        available_slots -= p;

        int col_idx = __builtin_ctz(p);
        queen_positions[row] = col_idx;

        backtrack(row + 1, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1);
    }
}

void solve() {
    cin >> n;
    solutions_count = 0;
    queen_positions.assign(n, 0);

    cout << "\n";
    backtrack(0, 0, 0, 0);
    cout << "Total solutions: " << solutions_count << "\n";
}

signed main() { solve(); }
