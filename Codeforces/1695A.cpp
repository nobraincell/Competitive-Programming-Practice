#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int max_val = INT_MIN;
        int max_i = -1, max_j = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val;
                cin >> val;
                if (val > max_val) {
                    max_val = val;
                    max_i = i;
                    max_j = j;
                }
            }
        }

        int h = max(max_i + 1, n - max_i);
        int w = max(max_j + 1, m - max_j);

        cout << h * w << "\n";
    }

    return 0;
}
