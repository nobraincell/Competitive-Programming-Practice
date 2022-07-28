/*
 * Union By Size
 */
struct DSU {
    int n;
    vector<int> parent, size;

    void init(int ssize) {
        n = ssize;
        parent = vector<int>(n+1);
        size = vector<int>(n+1, 1);

        for (int i = 0; i < n; ++i) {
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
