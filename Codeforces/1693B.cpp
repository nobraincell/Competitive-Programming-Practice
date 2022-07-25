#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<long long> l, r;
long long ans;

long long dfs(int v) {
    long long sum = 0;

    for (int u : adj[v]) {
        sum += dfs(u);
    }

    if (sum < l[v]) {
        ans++;
        return r[v];
    }
    else {
        return min(r[v], sum);
    }
}



int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        adj = vector<vector<int>>(n+1);
        l = vector<long long>(n+1);
        r = vector<long long>(n+1);
        ans = 0;

        for (int i = 2; i <= n; ++i) {
            int p;
            cin >> p;

            adj[p].push_back(i);
        }

        for (int i = 1; i <= n; ++i) {
            long long ll, rr;
            cin >> ll >> rr;

            l[i] = ll;
            r[i] = rr;
        }

        dfs(1);

        cout << ans << "\n";

    }

    return 0;
}
