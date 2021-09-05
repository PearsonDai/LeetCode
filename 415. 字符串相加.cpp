415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

提示：

num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式

class Solution {
public:
    string addStrings(string num1, string num2) {
        string str;
        int cur=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0||j>=0||cur!=0){
            if(i>=0) cur+=num1[i--]-'0';
            if(j>=0) cur+=num2[j--]-'0';
            str+=cur%10+'0';
            cur/=10;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};