#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, r, m;
        cin >> n >> r >> m;

        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1, 0);

        for (int i = 0; i < r; ++i) {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            int k, s;
            cin >> k >> s;
            q.push({k, s});
            vis[k] = k;
        }


        bool possible = true;
        while (!q.empty()) {
            int v = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (dist <= 0) continue;

            for (int u : adj[v]) {
                if (!vis[u]) {
                    vis[u] = vis[v];
                    q.push({u, dist - 1});
                }
                else {
                    if (vis[u] == vis[v]) {
                        continue;
                    }
                    else {
                        possible = false;
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) possible = false;
        }

        cout << (possible ? "Yes\n" : "No\n");
    }

    return 0;
}
