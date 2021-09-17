131. 分割回文串
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。

示例 1：

输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：

输入：s = "a"
输出：[["a"]]
 

提示：

1 <= s.length <= 16
s 仅由小写英文字母组成

class Solution {
public:
    bool isPalindrome(string str){
        int l=0,r=str.size()-1;
        while(l<r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void dfs(vector<vector<string>>& res, vector<string>& temp, string s, int startIdx){
        if(startIdx>=s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=1;i+startIdx<=s.size();i++){
            string str=s.substr(startIdx,i);
            if(isPalindrome(str)){
                temp.push_back(str);
                dfs(res,temp,s,startIdx+i);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(res,temp,s,0);
        return res;
    }
};