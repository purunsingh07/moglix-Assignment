# Longest Valid Parentheses

A C++ solution to find the length of the longest valid (well-formed) parentheses substring in a given string containing only `'('` and `')'`.

## Problem Statement

Given a string containing just the characters `'('` and `')'`, return the length of the longest valid (well-formed) parentheses substring.

### Examples

**Example 1:**
```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```

**Example 2:**
```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```

**Example 3:**
```
Input: s = ""
Output: 0
```

### Constraints

- `0 <= s.length <= 3 * 10^4`
- `s[i]` is `'('` or `')'`.

## Approach

This solution uses a **stack-based approach**:

1. Push `-1` onto the stack initially. This acts as a base index to correctly calculate lengths.
2. Iterate through the string:
   - If the character is `'('`, push its index onto the stack.
   - If the character is `')'`:
     - Pop the top of the stack.
     - If the stack becomes empty, push the current index — it becomes the new base for future calculations (since this `')'` has no match).
     - Otherwise, calculate the length of the current valid substring as `i - stack.top()` and update the maximum length found so far.

### Complexity

| Metric | Complexity |
|--------|-----------|
| Time   | O(n)      |
| Space  | O(n)      |

Where `n` is the length of the input string.

## Code

```cpp
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
```

## How to Run

1. Save the code above as `longest_valid_parentheses.cpp`.
2. Compile it using g++:
   ```bash
   g++ -o longest_valid_parentheses longest_valid_parentheses.cpp
   ```
3. Run the executable:
   ```bash
   ./longest_valid_parentheses
   ```

### Expected Output

```
Input: (() -> Output: 2
Input: )()()) -> Output: 4
Input: "" -> Output: 0
```

## License

This project is open-source and available for anyone to use and modify.
