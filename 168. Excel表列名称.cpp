168. Excel表列名称
给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

例如：

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

示例 1：

输入：columnNumber = 1
输出："A"
示例 2：

输入：columnNumber = 28
输出："AB"
示例 3：

输入：columnNumber = 701
输出："ZY"
示例 4：

输入：columnNumber = 2147483647
输出："FXSHRXW"

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber){
            --columnNumber;
            res+=(columnNumber%26)+'A';
            columnNumber/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

题解：
https://leetcode-cn.com/problems/excel-sheet-column-title/solution/excelbiao-lie-ming-cheng-by-leetcode-sol-hgj4/