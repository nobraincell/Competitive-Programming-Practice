#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> dp(m+1, 0);
        vector<int> appear(m+1, 0);
        vector<int> freq(m+1, 0);
        int mx = INT_MIN, mn = INT_MAX, ans;

        for (int i = 1; i <= m; ++i) {
            dp[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            appear[x] = 1;
            freq[x] = 1;
            mx = max(mx, x);
            mn = min(mn, x);
        }

        int ptr = mx;
        ans = mx - mn;
        for (int i = mx; i >= 1; --i) {
            for (long long j = (long long) i * i; j <= mx; j += i) {
                if (appear[j]) 
                    freq[dp[j]]--;

                dp[j] = min(dp[j], dp[j / i]);

                if (appear[j])
                    freq[dp[j]]++;
            }
            while (freq[ptr] == 0)
                ptr--;

            if (i <= mn)
                ans = min(ans, ptr - i);
        }

        cout << ans << "\n";
    }

    return 0;
}
