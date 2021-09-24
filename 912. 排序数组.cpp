912. 排序数组
给你一个整数数组 nums，请你将该数组升序排列。

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

class Solution {
public:
    int get_mid(vector<int>& nums, int left, int right){
        int key = rand() % (right - left + 1) + left;
        swap(nums[left], nums[key]);
        int pivot = nums[left];
        while(left < right){
            while(left < right && nums[right] >= pivot) right--;
            nums[left] = nums[right];
            while(left < right && nums[left] <= pivot) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
    void quick_sort(vector<int>& nums, int left, int right){
        if(left < right){
            int mid = get_mid(nums, left, right);
            quick_sort(nums, left, mid - 1);
            quick_sort(nums, mid + 1, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        quick_sort(nums, left, right);
        return nums;
    }
};