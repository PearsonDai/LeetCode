187. 重复的DNA序列
所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

示例 1：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：

输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
 

提示：

0 <= s.length <= 105
s[i] 为 'A'、'C'、'G' 或 'T'

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int sz = s.size();
        if(sz <= 10) return {};
        vector<string> res;
        unordered_map<string,int> hashmap;
        for(int i = 0; i + 10 <= sz; i++){
            string str = s.substr(i,10);
            hashmap[str]++;
        }
        for(auto it = hashmap.begin(); it != hashmap.end(); it++){
            if((*it).second > 1){
                res.push_back((*it).first);
            }
        }
        return res;
    }
};