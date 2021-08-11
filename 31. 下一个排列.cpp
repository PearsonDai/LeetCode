31. 下一个排列
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须 原地 修改，只允许使用额外常数空间。

示例 1：

输入：nums = [1,2,3]
输出：[1,3,2]
示例 2：

输入：nums = [3,2,1]
输出：[1,2,3]
示例 3：

输入：nums = [1,1,5]
输出：[1,5,1]
示例 4：

输入：nums = [1]
输出：[1]

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while(i>0){
            if(nums[i-1]<nums[i]){
                break;
            }
            i--;
        }
        if(i>0){
            for(int j=n-1;j>i-1;j--){
                if(nums[i-1]<nums[j]){
                    swap(nums[i-1],nums[j]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i,nums.end());
    }
};