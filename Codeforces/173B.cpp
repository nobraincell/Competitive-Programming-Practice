#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    vector<string> grids(n+1);
    vector<vector<vector<int>>> dist(n+1, vector<vector<int>>(m+1, vector<int>(4, INT_MAX)));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    for (int i = 0; i < n; ++i) {
            cin >> grids[i];
    }

    deque<array<int, 3>> q;
    q.push_front({n-1, m-1, 3}); // i, j, dir
    dist[n-1][m-1][3] = 0;

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int dir = q.front()[2];
        q.pop_front();

        int d = dist[x][y][dir];
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // do nothing and move
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (d < dist[nx][ny][dir]) {
                dist[nx][ny][dir] = d;
                q.push_front({nx, ny, dir});
            }
        }

        // try all four directions
        if (grids[x][y] == '#') {
            for (int i = 0; i < 4; ++i) {
                if (i != dir) {
                    if (d + 1 < dist[x][y][i]) {
                        dist[x][y][i] = d + 1;
                        q.push_back({x, y, i});
                    }
                }
            }
        }
    }

    if (dist[0][0][3] == INT_MAX) cout << -1;
    else cout << dist[0][0][3];

    cout << "\n";
    return 0;
}
