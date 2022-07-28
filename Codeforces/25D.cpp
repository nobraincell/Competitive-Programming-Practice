#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, size;

    void init(int ssize) {
        n = ssize;
        parent = vector<int>(n+1);
        size = vector<int>(n+1, 1);

        for (int i = 0; i <= n; ++i) {
            make_set(i);
        }
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    bool in_same_set(int a, int b) {
        return find_set(a) == find_set(b);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    DSU cities;
    cities.init(n);

    vector<pair<int, int>> roads;
    vector<pair<int, int>> missing_roads;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;

        if (cities.in_same_set(a, b)) {
            roads.push_back({a, b});
        }
        else {
            cities.union_sets(a, b);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (!cities.in_same_set(i, j)) {
                missing_roads.push_back({i, j});
                cities.union_sets(i, j);
            }
        }
    }

    cout << missing_roads.size() << "\n";
    for (int i = 0; i < missing_roads.size(); ++i) {
        cout << roads[i].first << " " << roads[i].second << " " << missing_roads[i].first << " " << missing_roads[i].second << "\n";
    }

    return 0;
}
