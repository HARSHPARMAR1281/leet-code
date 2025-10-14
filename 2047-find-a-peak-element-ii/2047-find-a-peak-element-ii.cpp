class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size(), L = 0, R = M - 1;
        while (L < R) {
            int mid = (L + R + 1) / 2;
            int left = mid - 1 >= 0 ? *max_element(begin(mat[mid - 1]), end(mat[mid - 1])) : -1;
            int cur = *max_element(begin(mat[mid]), end(mat[mid]));
            if (cur > left) L = mid;
            else R = mid - 1;
        }
        return { L, int(max_element(begin(mat[L]), end(mat[L])) - begin(mat[L])) };
    }
};