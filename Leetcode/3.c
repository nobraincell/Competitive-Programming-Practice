int max(int a, int b ) {
    return (a > b ? a : b);
}

int min(int a, int b) {
    return (a < b ? a : b);
}

int lengthOfLongestSubstring(char * s){
    
    if (strlen(s) <= 1) return strlen(s);
    
    int n = strlen(s);
    int ans = 1;
    int freq[128]={0};
    int i = 0, j = 0;
    
    freq[s[0]]++;
    while (j < n - 1) {
        if (freq[(int) s[j + 1]] == 0) {
            // i..j+1 is ok
            freq[(int) s[j + 1]]++;
            j++;
        }
        else {
            // i+1..j may be ok, 
            // it must be smaller than the last iteration, so it does not affect the result
            freq[(int) s[i]]--;
            i++;
        }
        ans = max(ans, j - i + 1);
    } 
    
    return ans;
}