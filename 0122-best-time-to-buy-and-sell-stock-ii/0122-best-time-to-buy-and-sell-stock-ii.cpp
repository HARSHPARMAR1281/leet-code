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
        vector<vector<long>> dp(n+1, vector<long>(2,0));
        //return profit(0, 1, prices, n, dp); memoisation
        // here on its tablulation by harsh parmar thakur singh

        
        dp[n][0] = 0;
        dp[n][1] = 0;
        //above was base case of reccursion 

        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                long fayda =0;
                if(buy){
                    fayda = max(-prices[idx] + dp[idx+1][0], 0 + dp[idx+1][1]);
                }
                else{
                    fayda = max(prices[idx] + dp[idx+1][1] , 0 + dp[idx+1][0]);
                }
                dp[idx][buy] = fayda;
            }
        }
        return dp[0][1];
    }
};