216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& temp, int first, int k, int n){
        if(n == 0){
            if(k == 0){
                res.push_back(temp);
            }
            return;
        }
        for(int i = first; i <= 9 && n - i >= 0; i++){
            temp.push_back(i);
            dfs(res, temp, i + 1, k - 1, n - i);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, temp, 1, k, n);
        return res;
    }
};