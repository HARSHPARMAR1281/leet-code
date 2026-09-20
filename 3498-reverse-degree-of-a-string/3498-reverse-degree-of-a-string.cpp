class Solution {
public:
    int reverseDegree(string s) {
       unordered_map<char,int> mpp;
       int n =26;
       for(char it = 'a' ; it<='z'; it++){
        mpp[it] = n;
        n--;
       }
       int sum = 0;
       for(int i = 0; i < s.size();i++){
        int val = mpp[s[i]]*(i+1);
        sum+= val;
       }
        return sum;
    }
};