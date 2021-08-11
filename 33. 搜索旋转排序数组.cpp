33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1
 

提示：

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums 中的每个值都 独一无二
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-10^4 <= target <= 10^4
 

进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？

//递归
class Solution {
public:
    int bisearch(vector<int>& nums, int left, int right, int target){
        if(left>right)return -1;
        int mid=(left+right)/2;
        if(nums[mid]==target)return mid;
        if(mid==left){
            return bisearch(nums,mid+1,right,target);
        }
        else if(mid==right){
            return bisearch(nums,left,mid-1,target);
        }
        else{
            if(nums[left]<=nums[mid-1]){
                if(nums[left]<=target&&nums[mid-1]>=target){
                    return bisearch(nums,left,mid-1,target);
                }
                else{
                    return bisearch(nums,mid+1,right,target);
                }
            }
            else{
                if(nums[mid+1]<=target&&nums[right]>=target){
                    return bisearch(nums,mid+1,right,target);
                }
                else{
                    return bisearch(nums,left,mid-1,target);
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        return bisearch(nums,left,right,target);
    }
};

//迭代
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)return -1;
        if(n==1){
            return (nums[0]==target)?0:-1;
        }
        int left=0,right=n-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target)return mid;
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target&&target<=nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if(nums[mid]<=target&&target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};