public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        //if(nums[0] + nums[1] == target) return [0, 1];
        int l =0 , h =0;
        int n = nums.Length;
        
        for(int i = 0; i< n; i++){
            for(int j = i+1 ; j< n; j++){
                if(nums[i] + nums[j] == target){
                    l = i;
                    h = j;
                    break;
                }
            } 
        }
        return [l , h];
    }
}