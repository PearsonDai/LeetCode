剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

提示：

0 <= num < 231

class Solution {
public:
    int translateNum(int num) {
        string str=to_string(num);
        int n=str.size();
        int fn_2=1,fn_1=1;
        int fn;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
            int temp=(str[i-2]-'0')*10+(str[i-1]-'0')*1;
            if(temp>=10&&temp<=25) fn=fn_2+fn_1;
            else fn=fn_1;
            fn_2=fn_1;
            fn_1=fn;
        }
        return fn;
    }
};