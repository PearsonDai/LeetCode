16. 最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res,dis=1e5;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target) return target;
                if(abs(target-sum)<dis){
                    dis=abs(target-sum);
                    res=sum;
                }
                if(sum>=target){
                    right--;
                    while(left<right&&nums[right+1]==nums[right]) right--;
                }
                else{
                    left++;
                    while(left<right&&nums[left-1]==nums[left]) left++;
                }
            }
        }
        return res;
    }
};