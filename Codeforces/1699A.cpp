#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        // set a = b and c = 0

        if (n % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        cout << n / 2 << " " << n / 2 << " " << 0 << "\n";
    }


    return 0;
}
