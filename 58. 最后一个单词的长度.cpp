58. 最后一个单词的长度
给你一个字符串 s，由若干单词组成，单词之间用单个或多个连续的空格字符隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

 

示例 1：

输入：s = "Hello World"
输出：5
示例 2：

输入：s = " "
输出：0

/*
class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag=0;
        int cnt=0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]!=' '&&flag==0){
                flag=1;
                cnt++;
            }
            else if(s[i]!=' '&&flag==1){
                cnt++;
            }
            else if(s[i]==' '&&flag==1){
                return cnt;
            }
        }
        return cnt;
    }
};
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]!=' ')++cnt;
            else if(s[i]==' '&&cnt!=0)return cnt;
        }
        return cnt;
    }
};