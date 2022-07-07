#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj; // adjacency list
vector<bool> vis; // node is visited or not

void dfs(int v) {
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    // initialization
    adj = vector<vector<int>>(n+1);
    vis = vector<bool>(n+1, false);
    vector<int> road;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // DFS
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
            road.push_back(i);
        }
    }
    cout << cnt - 1 << "\n";
    for (int i = 1; i < cnt; ++i) {
        cout << road[i-1] << " " << road[i] << "\n";
    }
    return 0;
}
