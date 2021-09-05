40. 组合总和 II
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

注意：解集不能包含重复的组合。 

 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
 

提示:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

class Solution {
public:
    void dfs(vector<vector<int>>& res,vector<int>&candidates, vector<int>& output,int idx, int target){
        if(target==0){
            res.push_back(output);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx&&candidates[i]==candidates[i-1]){
                continue;
            }
            output.push_back(candidates[i]);
            dfs(res,candidates,output,i+1,target-candidates[i]);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> output;
        dfs(res,candidates,output,0,target);
        return res;
    }
};