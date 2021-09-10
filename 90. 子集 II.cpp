90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, vector<bool>& used, int first){
        res.push_back(temp);
        for(int i=first;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
                continue;
            }
            temp.push_back(nums[i]);
            used[i]=true;
            dfs(res,temp,nums,used,i+1);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(res,temp,nums,used,0);
        return res;
    }
};