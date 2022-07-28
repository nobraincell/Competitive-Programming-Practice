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
    map<int, long long> ans;
    map<int, long long> cnt;
    int n = s.size();

    // for (auto i : z) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    
    for (int i = n-1; i > 0; --i) {
        cnt[z[i]]++;
        if (z[i] == n-i){
            ans[z[i]] += 2;
        }
        else if (ans.count(z[i])) {
            ans[z[i]]++;
        }
    }

    long long cur_cnt = 0;
    for (int i = n; i >= 1; --i) {
        if (ans.count(i)) {
            ans[i] += cur_cnt;
        }
        if (cnt.count(i)) {
            cur_cnt += cnt[i];
        }
    }


    ans[n]++;
    cout << ans.size() << "\n";
    for (auto a : ans) {
        cout << a.first << " " << a.second << "\n";
    }

    return 0;
}
