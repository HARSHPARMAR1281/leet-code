class Solution {
public:
    int sumbyD(vector<int> &nums, int div){
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
         int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (sumbyD(nums, m) <= threshold)
                h = m - 1;

            else
                l = m + 1;
        }
        return l;
    }
};