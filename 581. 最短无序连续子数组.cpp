581. 最短无序连续子数组
给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。

示例 1：

输入：nums = [2,6,4,8,10,9,15]
输出：5
解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
示例 2：

输入：nums = [1,2,3,4]
输出：0
示例 3：

输入：nums = [1]
输出：0

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxPre=INT_MIN,right=-1;
        int minPost=INT_MAX,left=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(maxPre>nums[i]){
                right=i;
            }else{
                maxPre=nums[i];
            }
            if(nums[n-1-i]>minPost){
                left=n-1-i;
            }else{
                minPost=nums[n-1-i];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};