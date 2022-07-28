#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    vector<int> z = z_function(s);
    int n = s.size();
    int mx_z = 0;
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        if (z[i] == n-i && z[i] <= mx_z) {
            ans = max(ans, z[i]);
        }

        mx_z = max(mx_z, z[i]);
    }

    if (ans == 0) {
        cout << "Just a legend\n";
    }
    else {
        for (int i = 0; i < ans; ++i) {
            cout << s[i];
        }
        cout << "\n";
    }

    return 0;
}
