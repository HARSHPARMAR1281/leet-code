class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int mini = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ans += nums[i] - mini;
        }

        return ans;
    }
};