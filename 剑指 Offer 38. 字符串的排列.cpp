剑指 Offer 38. 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 
限制：

1 <= s 的长度 <= 8

class Solution {
public:
    void dfs(unordered_set<string>& hashset, string& s, int first, int len){
        if(first==s.size()){
            hashset.insert(s);
            return;
        }
        for(int i=first;i<len;i++){
            swap(s[i],s[first]);
            dfs(hashset,s,first+1,len);
            swap(s[i],s[first]);
        }
    }
    vector<string> permutation(string s) {
        vector<string> res;
        unordered_set<string> hashset;
        int first=0;
        int len=s.size();
        dfs(hashset,s,first,len);
        for(auto it=hashset.begin();it!=hashset.end();++it){
            res.push_back(*it);
        }
        return res;
    }
};