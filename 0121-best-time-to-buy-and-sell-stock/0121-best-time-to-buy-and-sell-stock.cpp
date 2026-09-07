class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++){
            int cost = prices[i] - buy;
            maxprofit = max(maxprofit, cost);
            buy = min(buy , prices[i]);
        }
        return maxprofit;

    }
};