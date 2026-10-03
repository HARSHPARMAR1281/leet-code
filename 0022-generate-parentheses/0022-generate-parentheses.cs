public class Solution {

    void gparenthesis(int open, int close, int n, string output, IList<string> ans){
        if( open <= 0 && close <= 0){
            ans.Add(output);
        }

        if(open > 0){
            gparenthesis(open - 1 , close , n , output + "(", ans);
        }

        if(close>open){
 
            gparenthesis(open , close -1 , n , output + ")", ans);
 
        }
        
    }


    public IList<string> GenerateParenthesis(int n) {
        int open = n , close = n;
        string output = "";
        IList<string> ans  =new List<string>();
        gparenthesis(open , close , n , output, ans);
        return ans;
    }
}