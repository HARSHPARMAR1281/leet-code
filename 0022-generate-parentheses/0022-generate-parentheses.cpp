class Solution {
public:
    void generateParenthesisRecu(int left, int right, string *str, vector<string> *result) {
        if (left == 0 && right == 0) {
            result->emplace_back(*str);
        }
        if (left > 0) {
            str->push_back('(');
            generateParenthesisRecu(left - 1, right, str, result);
            str->pop_back();
        }
        if (left < right) {
            str->push_back(')');
            generateParenthesisRecu(left, right - 1, str, result);
            str->pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        generateParenthesisRecu(n, n, &str, &result);
        return result;
    }

private:
    
};