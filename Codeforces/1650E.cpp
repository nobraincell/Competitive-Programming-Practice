#include <bits/stdc++.h>
using namespace std;

int cntMoving(vector<int> schedule, int d) {
    int n = (int) schedule.size() - 1;
    int mx = 0, mn = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int curDiff = schedule[i] - schedule[i - 1] - 1;
        mx = max(mx, curDiff);
        mn = min(mn, curDiff);
    }

    return min(mn, max(d - schedule.back() - 1, (mx - 1) / 2));
}

void solve() {
    int n, d;
    cin >> n >> d;
    
    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    // finding position with shortest break
    int mn = d, minPos = -1;
    for (int i = 1; i <= n; ++i) {
        int curDiff = arr[i] - arr[i - 1] - 1;
        if (curDiff < mn) {
            mn = curDiff;
            minPos = i;
        }
    }

    // test moving minPos and the one before it
    // 1: moving minPos
    int ans;
    vector<int> schedule;
    for (int i = 0; i <= n; ++i) {
        if (i != minPos) {
            schedule.push_back(arr[i]);
        }
    }
    ans = cntMoving(schedule, d);

    // 2: moving the one before it
    if (minPos > 1) {
        schedule[minPos - 1] = arr[minPos];
    }
    ans = max(ans, cntMoving(schedule, d));

    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}