class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
           int count = 0;
        
        for(int i = 0; i < arr.size(); ++i){
            if(i == 0){
                if(count + arr[0]-1 >= k){
                    return k;
                }
                count += arr[0]-1;
            }else{
                if(count + arr[i] - arr[i-1] - 1 >= k){
                    return arr[i-1] + (k - count);
                }
                count += arr[i] - arr[i-1] - 1;
            }
          
        }
        return arr.back() + (k-count);
    }
};