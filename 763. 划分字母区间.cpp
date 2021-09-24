763. 划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 

提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> hash(26, 0);
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a'] = i;
        }
        int left = 0, rightmost = 0;
        for(int i = 0; i < s.size(); i++){
            rightmost = max(rightmost, hash[s[i] - 'a']);
            if(i == rightmost){
                res.push_back(rightmost - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};