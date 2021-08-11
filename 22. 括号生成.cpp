22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]

class Solution {
public:
    void dfs(vector<string>& res, string str, int left, int right){
        if(left==0&&right==0){
            res.push_back(str);
            return;
        }
        if(left==right){
            //剩余的左括号数和右括号数相等，必须使用左括号
            dfs(res,str+"(",left-1,right);
        }
        else if(left<right){
            if(left>0){
                dfs(res, str+"(", left-1, right);
            }
            dfs(res,str+")",left,right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res,"",n,n);
        return res;
    }
};