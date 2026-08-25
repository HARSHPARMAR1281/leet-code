class Solution {
public:
   
    int dfs(string &s, int l, int r , vector<vector<int>> &dp) {
        if (l >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        if (s[l] == s[r]) {
            return dp[l][r] = dfs(s, l + 1, r - 1 , dp);
        }

        return dp[l][r] = 1 + min(dfs(s, l + 1, r , dp) , dfs(s, l, r - 1 , dp));
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));

        return dfs(s, 0, n - 1 , dp);
    }
};
