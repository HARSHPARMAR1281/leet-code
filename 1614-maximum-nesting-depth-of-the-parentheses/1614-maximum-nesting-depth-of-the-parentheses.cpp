class Solution {
public:
    int maxDepth(string s) {
        int curr =0 , maxi = 0;
        for(auto it : s ){
            if(it == '('){
                curr++;
                maxi = max(curr , maxi);
            }
            else if(it == ')'){
                curr--;
                maxi = max(curr , maxi);
            }
        }
        return maxi;
    }
};