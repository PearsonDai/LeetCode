647. 回文子串
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：

输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

输入的字符串长度不会超过 1000 。

class Solution {
public:
    int countSubstrings(string s) {
        int cntRes=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=1;j++){
                int l=i;
                int r=i+j;
                while(l>=0&&r<n&&s[l--]==s[r++])cntRes++;
            }
        }
        return cntRes;
    }
};