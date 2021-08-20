416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return false;
        }
        int sum=0;
        int maxNum=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxNum=max(maxNum,nums[i]);
        }
        if(sum%2==1||maxNum>sum/2){
            return false;
        }
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(1+target,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][target];
    }
};