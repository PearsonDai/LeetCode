47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<bool>& used, vector<int>& nums){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true||i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
                continue;
            }
            temp.push_back(nums[i]);
            used[i]=true;
            dfs(res,temp,used,nums);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(res,temp,used,nums);
        return res;
    }
};