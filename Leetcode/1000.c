int min(int a, int b) {
    return (a < b ? a : b);
}

int mergeStones(int* stones, int stonesSize, int k){
    const int inf = 1e9;
    if ((stonesSize - 1) % (k - 1)) return -1;
    
    int dp[stonesSize][stonesSize];
    int pre[stonesSize + 1];
    
    for (int i = 0; i < stonesSize; ++i) {
        for (int j = 0; j < stonesSize; ++j) {
            dp[i][j] = inf;
        }
    }
    
    for (int i = 0; i < stonesSize; ++i) {
        dp[i][i] = 0;
    }
    
    pre[0] = 0;
    for (int i = 1; i <= stonesSize; ++i) {
        pre[i] = pre[i - 1] + stones[i - 1];
    }
    
    for (int len = 2; len <= stonesSize; ++len) {
        for (int i = 0; i <= stonesSize - len; ++i) {
            int j = i + len - 1;
            for (int m = i; m < j; m += k - 1) {
                dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
            }
            
            if ((len - 1) % (k - 1) == 0) dp[i][j] += (pre[j + 1] - pre[i]);
        }
    }
    return dp[0][stonesSize - 1];
}