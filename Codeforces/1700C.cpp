#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);
        vector<long long> diff(n+1,0);
        long long ans = 0, a0;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        // caculate difference array
        // if a[i+1] > a[i] -> decrease suffix up to i+1
        // if a[i+1] < a[i] -> decrease prefix up to i
        // all the moisture levels must be the same after
        // keep track on a[1] to know the no. of operations for increasing
        a0 = a[1];
        for (int i = 1; i < n; ++i) {
            diff[i] = a[i + 1] - a[i];
            
            ans += (long long) abs(diff[i]);
            if (diff[i] < 0) a0 -= (long long) abs(diff[i]);
        }

        cout << ans + abs(a0) << "\n";

    }

    return 0;
}
