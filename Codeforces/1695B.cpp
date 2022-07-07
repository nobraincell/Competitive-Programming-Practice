#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        int min_val = INT_MAX;
        int min_i = -1;
        for (int i = 1; i <= n; ++i) {
            int val;
            cin >> val;
            if (val < min_val) {
                min_val = val;
                min_i = i;
            }
        }

        if (n % 2 == 1) {
            cout << "Mike\n";
            continue;
        }

        cout << (min_i % 2 == 1 ? "Joe" : "Mike") << "\n";
    }

    return 0;
}
