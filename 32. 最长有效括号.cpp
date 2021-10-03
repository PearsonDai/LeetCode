32. 最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：

输入：s = ""
输出：0
 

提示：

0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stk.push(i);
            }
            else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }
                else{
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};