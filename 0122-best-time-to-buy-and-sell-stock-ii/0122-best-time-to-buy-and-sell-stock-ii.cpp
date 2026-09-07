class Solution {
public:
    int profit(int idx, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        if(idx >= n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int fayda;
        if(buy){
            fayda = max(-prices[idx] + profit(idx+1, 0, prices, n, dp) , 0 + profit(idx+1, 1, prices, n, dp));
        }
        else{
            fayda = max(prices[idx] + profit(idx+1, 1, prices, n, dp) , 0 + profit(idx+1, 0, prices, n, dp));
        }

        return dp[idx][buy] = fayda;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return profit(0, 1, prices, n, dp);
    }
};