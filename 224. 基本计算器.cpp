224. 基本计算器
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23

提示：

1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式

class Solution {
public:
    int calculate(string s) {
        long res = 0;
        int n = s.size();
        stack<int> opStk;
        opStk.push(1);
        int sign = 1;
        int i = 0;
        while(i < n){
            if(s[i] == ' '){
                i++;
            }
            else if(s[i] == '+'){
                sign = opStk.top();
                i++;
            }
            else if(s[i] == '-'){
                sign = -1 * opStk.top();
                i++;
            }
            else if(s[i] == '('){
                opStk.push(sign);
                i++;
            }
            else if(s[i] == ')'){
                opStk.pop();
                i++;
            }
            else{
                long num = 0;
                while(i < n && isdigit(s[i])){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                res += sign * num;
            }
        }
        return res;
    }
};