class Solution {
public:
    int robHelper(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i]; 
        int p = nums[i] + robHelper(nums, i + 2, dp);
        int np = robHelper(nums, i + 1, dp);
        return dp[i] = max(p, np);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> dp1(nums1.size(), -1);
        int case1 = robHelper(nums1, 0, dp1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        vector<int> dp2(nums2.size(), -1);
        int case2 = robHelper(nums2, 0, dp2);
        return max(case1, case2);
    }
};