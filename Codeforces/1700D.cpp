#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> volume(n+1);
    vector<long long> dp(n+1, 0);
    vector<long long> pref(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> volume[i];
        pref[i] = pref[i-1] + volume[i];
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = max(dp[i-1], (pref[i] + i - 1) / i);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        long long t;
        cin >> t;
        long long l = 1, r = n + 1;


        while (l < r) {
            long long m = (l + r) / 2;
            long long check = max(dp[m], (pref[n] + m - 1) / m);

            if (check > t) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        cout << (r <= n ? r : -1) << "\n";
    }
    return 0;
}
