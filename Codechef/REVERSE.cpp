#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;
vector<bool> vis;
vector<int> d;

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    adj = vector<vector<pair<int, int>>>(n + 1);
    d = vector<int>(n + 1, INT_MAX);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back({y, 0});
        adj[y].push_back({x, 1});
    }

    deque<int> q1;
    q1.push_front(1);
    d[1] = 0;

    while (!q1.empty()) {
        int v = q1.front();
        q1.pop_front();

        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1) 
                    q1.push_back(u);
                else   
                    q1.push_front(u);
            }
        }
    }

    
    cout << (d[n] == INT_MAX ? -1 : d[n]) << "\n";
    return 0;
}
