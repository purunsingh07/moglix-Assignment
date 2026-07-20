#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1); // base index for length calculation

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                st.pop();
                if (st.empty()) {
                    st.push(i); // update base for next valid substring
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    string s1 = "(()";
    cout << "Input: " << s1 << " -> Output: " << sol.longestValidParentheses(s1) << endl; // 2

    string s2 = ")()())";
    cout << "Input: " << s2 << " -> Output: " << sol.longestValidParentheses(s2) << endl; // 4

    string s3 = "";
    cout << "Input: \"\" -> Output: " << sol.longestValidParentheses(s3) << endl; // 0

    return 0;
}