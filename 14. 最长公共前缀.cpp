14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsSize=strs.size();
        int firstLen=strs[0].size();
        string strRet;
        if(strs.empty()==true)return strRet;
        if(strsSize==1)return strs[0];
        for(int i=0;i!=firstLen;++i){
            for(int j=1;j!=strsSize;++j){
                //这里别忘了加上'i!=strs[j].size()'的判断条件，
                //否则虽然也会通过编译，但是会可能出现超出字符串范围的情况。
                if(i==strs[j].size()||strs[j][i]!=strs[0][i]){
                    return strRet;
                }
            }
            strRet.push_back(strs[0][i]);
        }
        return strRet;
    }
};