class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s, int l, int r) {
        if (l >= r)
            return true;
        if (dp[l][r] != -1)
            return dp[l][r];
        if (s[l] != s[r])
            return dp[l][r] = false;

        return dp[l][r] = isPalindrome(s, l + 1, r - 1);
    }



    string longestPalindrome(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        start = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
