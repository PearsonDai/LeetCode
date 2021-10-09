剑指 Offer 43. 1～n 整数中 1 出现的次数
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31
注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        int curr = n % 10, low = 0, high = n / 10;
        long digit = 1;
        while(n != 0){
            if(curr == 0){
                res += high * digit;
            }
            else if(curr == 1){
                res += high * digit + low + 1;
            }
            else{
                res += (high + 1) * digit;
            }
            low += curr * digit;
            high /= 10;
            n /= 10;
            curr = n % 10;
            digit *= 10;
        }
        return res;
    }
};