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

| Metric - Complexity |
| Time   -  O(n)      |
| Space  -  O(n)      |

Where `n` is the length of the input string.


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


