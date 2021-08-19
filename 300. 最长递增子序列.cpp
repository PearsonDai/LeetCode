300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1

//动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            int tempMax=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    tempMax=max(tempMax,dp[j]);
                }
            }
            dp[i]=1+tempMax;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

//动态规划+双指针
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>res.back()){
                res.push_back(nums[i]);
            }
            else{
                int left=0,right=res.size()-1;
                while(left<=right){
                    int mid=(left+right)/2;
                    if(nums[i]>res[mid]){
                        left=mid+1;
                    }
                    else{
                        right=mid-1;
                    }
                }
                res[left]=nums[i];
            }
        }
        return res.size();
    }
};