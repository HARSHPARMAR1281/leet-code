class Solution {
public:
    int dfs(int i , int j, string &word1, string &word2, vector<vector<int>> &dp){
        int n = word1.length();
        int m = word2.length();
        
        if(i >= n && j < m) return m - j;
        else if( j>=m && i < n) return n-i;
        if(i >= n && j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = dfs(i+1 , j+1, word1 , word2, dp);
        return dp[i][j] = 1 + min(dfs(i+1 , j, word1 , word2, dp) , dfs(i , j+1, word1, word2, dp));

    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return dfs(0, 0, word1, word2, dp);
    }
};