#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp3(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp4(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    // lahub before meeting
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i - 1 > 0) dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
            if (j - 1 > 0) dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
            dp1[i][j] += arr[i][j];
        }
    }

    // lahubina before meeting
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (i + 1 <= n) dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
            if (j - 1 > 0) dp2[i][j] = max(dp2[i][j], dp2[i][j - 1]);
            dp2[i][j] += arr[i][j];
        }
    }

    // lahub after meeting
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (i + 1 <= n) dp3[i][j] = max(dp3[i][j], dp3[i + 1][j]);
            if (j + 1 <= m) dp3[i][j] = max(dp3[i][j], dp3[i][j + 1]);
            dp3[i][j] += arr[i][j];
        }
    }

    // lahubina after meeting
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if (i - 1 > 0) dp4[i][j] = max(dp4[i][j], dp4[i - 1][j]);
            if (j + 1 <= m) dp4[i][j] = max(dp4[i][j], dp4[i][j + 1]);
            dp4[i][j] += arr[i][j];
        }
    }

    // meeting
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 || i == n || j == 1 || j == m) continue;
            // lahub go right, lahubina go up
            ans = max(ans, dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j]);
            // lahub go down, lahubina go right
            ans = max(ans, dp2[i][j - 1] + dp4[i][j + 1] + dp3[i + 1][j] + dp1[i - 1][j]);
        }
    }

    cout << ans << "\n";
    return 0;
}