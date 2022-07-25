#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree {
    int n;
    vector<T> tree;

    void build(string a, int size) {
        n = size;
        tree = vector<T>(4 * size);
        build(a, 1, 0, n - 1);
    }

    void build(string a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = (1 << (a[tl]-'a'));
        } 
        else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            tree[v] = tree[v*2] | tree[v*2+1];
        }
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm)) | query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, char new_val) {
        if (tl == tr) {
            tree[v] = (1 << (new_val - 'a'));
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = tree[v*2] | tree[v*2+1];
        }
    }
};


int main() {
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    SegTree<long long> segtree;
    segtree.build(s, s.size());

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            segtree.update(1, 0, segtree.n - 1, pos-1, c);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << __builtin_popcount(segtree.query(1, 0, segtree.n - 1, l-1, r-1)) << "\n";
        }
    }

    return 0;
}
