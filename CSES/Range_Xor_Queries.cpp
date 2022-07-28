#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree {
    int n;
    vector<T> tree;

    T combine(T a, T b) {
        return a ^ b;
    }

    void init(T* a, int size) {
        n = size;
        tree = vector<T>(4 * size);
        build(a, 1, 0, n - 1);
    }

    void build(T* a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } 
        else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            tree[v] = combine(tree[v*2], tree[v*2+1]);
        }
    }

    T query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        T a = query(v*2, tl, tm, l, min(r, tm)),
          b = query(v*2+1, tm+1, tr, max(l, tm+1), r);
        return combine(a, b);
    }

    void update(int pos, T new_val) {
        update(1, 0, n-1, pos, new_val);
    }

    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = combine(tree[v*2], tree[v*2+1]);
        }
    }
};


int main() {
    ios::sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;

    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegTree<long long> st;
    st.init(a, n);

    while (q--) {
        int l, r;
        cin >> l >> r;

        l--, r--;
        cout << st.query(l, r) << "\n";
    }

    return 0;
}
