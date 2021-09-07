77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
 

提示：

1 <= n <= 20
1 <= k <= n

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<bool>& used, int n, int first, int k){
        if(k==0){
            res.push_back(temp);
            return;
        }
        for(int i=first;i<=n;i++){
            if(used[i]==false){
                temp.push_back(i);
                used[i]=true;
                dfs(res,temp,used,n,i+1,k-1);
                used[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(n+1,false);
        dfs(res,temp,used,n,1,k);
        return res;
    }
};