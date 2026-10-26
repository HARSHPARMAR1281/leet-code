class Solution {
public:

    int dfs(int i , int j, int m, int n, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1) return 1;
        if(i>=m && j >=n) return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int right = 0;
        if(j+1 < n) right = dfs(i, j+1, m, n, dp);
        int down = 0;
        if(i+1 < m) down = dfs(i+1, j, m, n, dp);

        return dp[i][j] =right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int >> dp(m,vector<int> (n,-1));
        return dfs(0,0,m,n,dp);
    }
};