class Solution {
public:
    
    int f(vector<vector<int>> &triangle,int row,int col,vector<vector<int>>&dp){
        if(row >= triangle.size()-1) return triangle[row][col];
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        
        int d = f(triangle,row+1, col,dp);
        int ds = f(triangle, row+1, col+1,dp);
        dp[row][col] = triangle[row][col]+min(d,ds);
        return dp[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size());
    
    for (int i = 0; i < triangle.size(); i++)
        dp[i] = vector<int>(triangle[i].size(), INT_MAX);
    
    
    return f(triangle,0,0,dp);
    }
};