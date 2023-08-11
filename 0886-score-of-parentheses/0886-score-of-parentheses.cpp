class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int cnt{}, depth{};
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                depth++;
            else 
            {
                depth--;
                if (i && s[i - 1] == '(')
                    cnt += pow(2, depth);
            }
        }

        return cnt;
    }
};