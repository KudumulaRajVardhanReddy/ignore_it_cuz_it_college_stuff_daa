#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> board;
vector<int> col, diag1, diag2;

void solve_nqueens(int r) {
    if (r == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << (board[i][j] ? "Q" : ".");
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (col[c] || diag1[r + c] || diag2[r - c + n - 1]) continue;

        board[r][c] = 1;
        col[c] = diag1[r + c] = diag2[r - c + n - 1] = 1;

        solve_nqueens(r + 1);

        board[r][c] = 0;
        col[c] = diag1[r + c] = diag2[r - c + n - 1] = 0;
    }
}

void solve() {
    cin >> n;

    board.assign(n, vector<int>(n, 0));

    col.assign(n, 0);
    diag1.assign(2 * n, 0);
    diag2.assign(2 * n, 0);

    solve_nqueens(0);
}

signed main() { solve(); }
