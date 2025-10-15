class Solution {
public:
vector<int> merge(const vector<int>& arr1, const vector<int>& arr2) {
    int m = arr1.size(), n = arr2.size();
    vector<int> arr;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            arr.push_back(arr1[i++]);
        } else {
            arr.push_back(arr2[j++]);
        }
    }
    while (i < m) arr.push_back(arr1[i++]);
    while (j < n) arr.push_back(arr2[j++]);
    return arr;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr = merge(nums1, nums2);
    int n = arr.size();
    if (n % 2 == 1)
        return arr[n / 2];
    else
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
};