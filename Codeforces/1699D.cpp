#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        // initialization
        vector<int> a(n+1, 0);
        vector<int> dp(n+2, 0);
        vector<int> freq(n+1, 0);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        // can a[1..i-1] be totally deleted?
        int max_freq = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i - 1) % 2 == 0) {
                dp[i] = (max_freq <= (i-1) / 2 ? 1 : 0);
            }
            else {
                dp[i] = 0;
            }
            max_freq = max(max_freq, ++freq[a[i]]);
        }

        dp[n+1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (dp[i] > 0) {
                max_freq = 0;
                freq = vector<int>(n+1, 0);
                for (int j = i+1; j <= n+1; ++j) {
                    int len = j - i - 1;
                    if (j == n + 1 || a[i] == a[j]) {
                        if (len % 2 == 0 && max_freq <= len / 2) {
                            dp[j] = max(dp[j], dp[i] + 1);
                        }
                    }
                    if (j <= n)
                        max_freq = max(max_freq, ++freq[a[j]]);
                }
            }
        }

        cout << dp[n+1] - 1 << "\n";
    }

    return 0;
}
