46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 

提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同

class Solution {
public:
    void backTrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        if(first==len){
            res.push_back(output);
            return;
        }
        for(int i=first;i<len;i++){
            swap(output[first],output[i]);
            backTrack(res, output, first+1, len);
            swap(output[first],output[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int first=0,len=nums.size();
        backTrack(res,nums,first,len);
        return res;
    }
};

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<bool>& used, vector<int>& nums){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true) continue;
            temp.push_back(nums[i]);
            used[i]=true;
            dfs(res,temp,used,nums);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        dfs(res,temp,used,nums);
        return res;
    }
};
