public class Solution {
    public int LengthOfLongestSubstring(string s) {
        HashSet<char> st = new HashSet<char>();
        int l = 0;
       
        
        int maxlen = 0;
        for(int r = 0; r<s.Length; r++){
            while( st.Contains(s[r]) ){
                st.Remove(s[l]);
                l = l+1;
            }
            st.Add(s[r] );
            maxlen = Math.Max(maxlen, r-l+1);

        }




        // for(int i = 0; i< s.Length ; i++){
        //     int len = 0;
        //     if(!st.Contains(s[i]) ){
        //         r = r+1;
        //         st.Add(s[i]);
        //     }
        //     else {
                
        //         l = l+1;
                
        //     }
        //     len = r-l;
        //     maxlen = Math.Max(len , maxlen);
        // }
        return maxlen  ;
    }
}