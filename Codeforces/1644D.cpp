#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<int> opX(q), opY(q);
    for (int i = 0; i < q; ++i) {
        cin >> opX[i] >> opY[i];
    }

    long long ans = 1;
    set<int> uX, uY;
    for (int i = q - 1; i >= 0; --i) {
        bool valid = false;
        // the row will not be recolored after this operation
        if (!uX.count(opX[i])) {
            uX.insert(opX[i]);
            valid = true;
        }
        // the column will not be recolored after this operation
        if (!uY.count(opY[i])) {
            uY.insert(opY[i]);
            valid = true;
        }

        // the possibility is k colors
        if (valid) {
            ans = (ans * k) % MOD;
        }

        // terminate early when all rows/columns are colored = the whole sheet is colored
        if (uX.size() == n || uY.size() == m) {
            break;
        }
    }

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}