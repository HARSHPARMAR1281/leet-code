class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length() ) return -1;
        string check = haystack.substr(0, needle.length());
        int l = 0, r = needle.length() -1;
      
        while(r<haystack.length()){
            if(check == needle )return l;
            
            l++;
            r++;
            check = haystack.substr(l, needle.length());
         
        }
        return -1;
    }
};