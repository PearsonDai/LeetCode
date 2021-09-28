227. 基本计算器 II
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

示例 1：

输入：s = "3+2*2"
输出：7
示例 2：

输入：s = " 3/2 "
输出：1
示例 3：

输入：s = " 3+5 / 2 "
输出：5
 

提示：

1 <= s.length <= 3 * 105
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
s 表示一个 有效表达式
表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
题目数据保证答案是一个 32-bit 整数

class Solution {
public:
    int calculate(string s) {
        stack<long> stk;
        char presign = '+';
        long res = 0;
        long temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                temp = temp * 10 +(s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1){
                if(presign == '+'){
                    stk.push(temp);
                }
                else if(presign == '-'){
                    stk.push(-1*temp);
                }
                else if(presign == '*'){
                    long val = stk.top();
                    stk.pop();
                    stk.push(val * temp);
                }
                else{
                    long val = stk.top();
                    stk.pop();
                    stk.push(val / temp);
                }
                temp = 0;
                presign = s[i];
            }
        }
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};