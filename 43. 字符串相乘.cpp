43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        string ans="0";
        int m=num1.size(),n=num2.size();
        for(int i=n-1;i>=0;i--){
            string curr="";
            for(int j=n-1;j>i;j--){
                curr.push_back('0');
            }
            int carry=0;
            for(int j=m-1;j>=0;j--){
                int mul=(num2[i]-'0')*(num1[j]-'0')+carry;
                curr.push_back(mul%10+'0');
                carry=mul/10;
            }
            while(carry>0){
                curr.push_back(carry%10+'0');
                carry/=10;
            }
            reverse(curr.begin(),curr.end());
            ans=addStrings(ans,curr);
        }
        return ans;
    }
    string addStrings(string a, string b){
        string res="";
        int i=a.size()-1,j=b.size()-1;
        int cur=0;
        while(i>=0||j>=0||cur!=0){
            if(i>=0) cur+=a[i--]-'0';
            if(j>=0) cur+=b[j--]-'0';
            res.push_back(cur%10+'0');
            cur/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int m=num1.size();
        int n=num2.size();
        string ans(m+n,'0');
        for(int j=n-1;j>=0;j--){
            for(int i=m-1;i>=0;i--){
                int mul=(num1[i]-'0')*(num2[j]-'0')+ans[i+j+1]-'0';
                ans[i+j+1]=mul%10+'0';
                ans[i+j]=(mul/10+ans[i+j]-'0')+'0';
            }
        }
        return ans[0]=='0'?ans.substr(1,m+n-1):ans;
    }
};