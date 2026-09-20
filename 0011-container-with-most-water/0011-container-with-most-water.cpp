class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        
        int l = 0;
        int r = height.size() -1;
        while(l<r){
            int area = 0;
            if(height[l] < height[r] ) area = height[l] * (r-l);
            else area = height[r] * (r-l);
            ans = max(ans, area);
            if(height[r] > height[l]) l++;
            else r--;
        }





        // for(int i = 0; i< height.size(); i++){
        //     for(int j = i ; j< height.size(); j++){
        //         int area ;
        //         if(height[i] < height[j] ) area = height[i] * abs(i-j);
        //         else area = height[j] * abs(i-j);
                
        //         ans = max(area, ans);
                
        //     }
        // }
        return ans;
    }
};