class Solution {
public:
    void f(int open, int close, int n, vector<string> &ans,string output){
        if(open == 0&& close == 0) {
            ans.push_back(output);
            return;
        }
        if(open>0){
            output+='(';
            f(open-1,close,n,ans,output);
            output.pop_back();
        }
        if(close>open){
            output+=')';
            f(open,close-1,n,ans,output);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n,close = n;
        string output = "";
        f(open,close,n,ans,output);
        return ans;
    }
};