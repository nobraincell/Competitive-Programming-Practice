#include <bits/stdc++.h>
using namespace std;
#define MAXN 400010
long long sum[MAXN];
long long a[MAXN];

void build(int n) {
    int ptr = n;
    while (ptr > 0) {
        sum[ptr] = sum[ptr*2] + sum[ptr*2+1];
        ptr -= 1;
    }
}

long long rangeSum(int n, int l, int r) {
    l += n, r += n;
    long long sm = 0;
    while (l <= r) {
        if (l % 2 == 1) sm += sum[l++];
        if (r % 2 == 0) sm += sum[r--];
        l /= 2, r /= 2;
    }
    return sm;
}

void update(int n, int idx, int val) {
    a[idx] = sum[idx + n] = val;
    int ptr = idx+n;
    for (ptr = ptr / 2; ptr > 0; ptr /= 2) {
        sum[ptr] = sum[ptr*2] + sum[ptr*2+1];
    }

}

int main() {
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i+n] = a[i];
    }

    build(n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(n, k, u);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << rangeSum(n, a, b) << "\n";
        }
    }

    return 0;
}
