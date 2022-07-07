#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;


        long long ans = 0;
        // move right 
        ans += (m * (m + 1)) / 2;

        // move down
        ans += ((n * (n - 1)) / 2) * m;
        ans += m * (n - 1);

        cout << ans << "\n";
    }
    return 0;
}
