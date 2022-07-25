#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n+1, 0), b(n+1);
        vector<pair<int, int>> bounds(n+1);

        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            bounds[i] = {i / (b[i] + 1) + 1, i};
        }

        sort(bounds.begin(), bounds.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int j = 1;
        for (int i = 1; i <= n; ++i) {
            while (j <= n && bounds[j].first == i) {
                int id = bounds[j++].second;
                pq.push({b[id] ? id / b[id] : n, id});
            }

            a[pq.top().second] = i;
            pq.pop();
        }

        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
