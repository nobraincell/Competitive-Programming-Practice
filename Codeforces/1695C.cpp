#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        bitset<1001> dp[n+1][m+1];
        vector<vector<int>> mp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mp[i][j];
            }
        }

        if ((n + m) % 2 == 0) {
            cout << "NO\n";
            continue;
        }

        dp[0][1][0] = dp[1][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (mp[i-1][j-1] == 1) {
                    dp[i][j] = (dp[i-1][j] | dp[i][j-1]) << 1;
                }
                else {
                    dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
                }
            }
        }

        if (dp[n][m][(n + m) / 2]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
