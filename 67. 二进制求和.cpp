67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        //此处使用reverse是为了不用在res字符串的开头调用insert。
        //reverse之后直接可以按位操作，依次从左往右进行
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0,carry=0;
        string res="";
        //倘若最后i和j都用尽了，carry若还在，则把carry对应的位放在最后一个位置。
        //因此carry也是我们的判断条件之一。
        while(i<a.size()||j<b.size()||carry){
            int tmpA=0,tmpB=0,N=2;
            if(i<a.size())tmpA=a[i++]-'0';
            if(j<b.size())tmpB=b[j++]-'0';
            res+=(tmpA+tmpB+carry)%N+'0';
            carry=(tmpA+tmpB+carry)/N;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};