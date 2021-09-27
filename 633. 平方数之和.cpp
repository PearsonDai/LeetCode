633. 平方数之和
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

示例 1：

输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
示例 2：

输入：c = 3
输出：false
示例 3：

输入：c = 4
输出：true
示例 4：

输入：c = 2
输出：true
示例 5：

输入：c = 1
输出：true
 

提示：

0 <= c <= 231 - 1

//sqrt方法
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i = 0; i * i <= c; i++){
            double j = sqrt(c - i * i);
            if(j == (int)j){
                return true;
            }
        }
        return false;
    }
};

//双指针方法
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (long)(sqrt(c));
        while(left <= right){
            long sum = left * left + right * right;
            if(sum == c){
                return true;
            }
            else if(sum > c){
                right--;
            }
            else{
                left++;
            }
        }
        return false;
    }
};