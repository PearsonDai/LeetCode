169. 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：

输入：[3,2,3]
输出：3
示例 2：

输入：[2,2,1,1,1,2,2]
输出：2
 
进阶：

尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。

/*
摩尔投票算法：
我们在一开始维护一个candidate(第一个数，并++count)，我们在遍历数组的过程中，每遇到一个数，
便将该数与candidate比较，如果该数等于candidate则令count+1，否则令count-1.当count变为0的时候，
则将candidate变成新遍历到的值。
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=-1,count=0;
        for(int i=0;i<nums.size();++i){
            if(count==0){
                candidate=nums[i];
                count++;
            }
            else if(candidate==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};