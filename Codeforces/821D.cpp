#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grids(n, vector<int>(m, 0));

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        grids[x-1][y-1] = 1;
    }

    deque<array<int, 3>> q;
    q.push({0, 0, -1});

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int dir = q.front()[2];

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && nx < m) {
                if (!grids[nx][ny]) {
                    push_front({})
                }
            }
        }
    }

    return 0;
}
