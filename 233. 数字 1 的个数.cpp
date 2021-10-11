233. 数字 1 的个数
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

示例 1：

输入：n = 13
输出：6
示例 2：

输入：n = 0
输出：0
 

提示：

0 <= n <= 109

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        int low = 0, high = n / 10, curr = n % 10;
        long digit = 1;
        while(n > 0){
            if(curr == 0){
                res += high * digit;
            }
            else if(curr == 1){
                res += high * digit + low + 1;
            }
            else{
                res += (high + 1) * digit;
            }
            low = curr * digit + low;
            curr = high % 10;
            high /= 10;
            digit *= 10;
            n /= 10;
        }
        return res;
    }
};