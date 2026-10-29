#include <bits/stdc++.h>
using namespace std;

#define int long long

class Item { public: int val, wt, id; };

void solve() {
    int n, w; cin >> n >> w;
    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        cin >> items[i].val >> items[i].wt;
        items[i].id = i;
    }

    int curr_wt = 0, total_val = 0;
    vector<int> picked;
  
    for (int i = 0; i < n; ++i) {
        if (curr_wt + items[i].wt <= w) {
            curr_wt += items[i].wt;
            total_val += items[i].val;
            picked.push_back(items[i].id + 1);
        }
    }

    cout << "Total value : " << total_val << "\n"; 
    cout << "Picked items : ";
    for (auto& i : picked) cout << i << " ";
    cout << "\n";
}

signed main() { solve(); }
