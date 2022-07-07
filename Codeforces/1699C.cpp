#include <bits/stdc++.h>
using namespace std;
#define MOD (long long) 1000000007 

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> pos(n, -1);

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            pos[x] = i;
        }

        long long ans = 1;
        int l, r;
        l = r = pos[0];

        for (int i = 1; i < n; ++i) {
            if (pos[i] > l && pos[i] < r) {
                long long interval = r - l - i + 1;
                ans = (ans * interval) % MOD;
            }
            else {
                l = min(l, pos[i]);
                r = max(r, pos[i]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
