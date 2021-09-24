567. 字符串的排列
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，s1 的排列之一是 s2 的 子串 。

示例 1：

输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false
 

提示：

1 <= s1.length, s2.length <= 104
s1 和 s2 仅包含小写字母

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sz1 = s1.size();
        int sz2 = s2.size();
        if(sz1 > sz2) return false;
        vector<int> hash(26, 0);
        for(int i = 0; i < sz1; i++){
            hash[s1[i] - 'a']++;
        }
        int l = 0, r = 0;
        while(r < sz2 && r - l < sz1){
            hash[s2[r] - 'a']--;
            while(hash[s2[r] - 'a'] < 0){
                hash[s2[l] - 'a']++;
                l++;
            }
            r++;
        }
        if(r - l == sz1) return true;
        return false;
    }
};