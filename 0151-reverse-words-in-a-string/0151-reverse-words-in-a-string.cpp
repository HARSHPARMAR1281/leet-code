class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string word = "";
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ' ') {
                if (!word.empty()) {
                    stk.push(word);
                    word = "";
                }
            }
            else {
                word.push_back(s[i]);
            }
        }
        if (!word.empty())
            stk.push(word);

        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();

            if (!stk.empty())
                ans += " ";
        }
        return ans;
    }
};