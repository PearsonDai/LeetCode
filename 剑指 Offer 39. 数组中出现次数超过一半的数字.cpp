剑指 Offer 39. 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：

1 <= 数组长度 <= 50000

class Solution {
public:
//摩尔投票法：从第一个数开始遍历，并将其设置为candidate，cnt初始化为1，当遍历到一个新的数，若该数与
//当下的candidate相等，则cnt++，否则cnt--。当遍历到某个数发现此时cnt=0，则将当下的数赋给candidate，并
//++cnt。最后剩下的candidate就是众数。
    int majorityElement(vector<int>& nums) {
        int candidate,cnt=0;
        for(int& num:nums){
            if(cnt==0){
                candidate=num;
                cnt++;
            }
            else if(num==candidate){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candidate;
    }
};