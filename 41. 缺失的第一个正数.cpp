41. 缺失的第一个正数
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 

示例 1：

输入：nums = [1,2,0]
输出：3
示例 2：

输入：nums = [3,4,-1,1]
输出：2
示例 3：

输入：nums = [7,8,9,11,12]
输出：1
 

提示：

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int res = n + 1;
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n + 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(abs(nums[i]) >= 1 && abs(nums[i]) <= n){
                int idx = abs(nums[i]) - 1;
                if(nums[idx] > 0){
                    nums[idx] *= -1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                res = i + 1;
                break;
            }
        }
        return res;
    }
};