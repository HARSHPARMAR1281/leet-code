class Solution {
public:
    int solve(vector<int>& nums, int i, int target) {
        if (i == nums.size()) {
            return target == 0;
        }      
        int plus = solve(nums, i + 1, target - nums[i]);
        int minus = solve(nums, i + 1, target + nums[i]);
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};
