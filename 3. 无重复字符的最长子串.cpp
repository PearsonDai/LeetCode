3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0

//一次遍历，使用hashmap，不需要erase，覆盖掉重复的值。
//进一步提高了时空效率。免去了不必要的重复。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0;
        unordered_map<char,int> hashmap;
        int beg=0,end=0;//记录窗口的左右索引号
        for(int i=0;i<s.size();i++){
            if(hashmap.find(s[i])!=hashmap.end()){
                //先记录下此时的子串长度
                cnt=max(cnt,end-beg);
                if(beg<=hashmap[s[i]]){
                    //如果此时窗口的左端点比重复出现的字符所在索引小的话，改变beg
                    beg=hashmap[s[i]]+1;
                } 
            }
            hashmap[s[i]]=i;
            end++;
        }
        return max(cnt,end-beg);
    }
};

//hashset一边将窗口右移，一边将上一个字符从Hashset中清除。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0;
        unordered_set<char> hashset;
        int right=0;
        for(int i=0;i<s.size();i++){
            if(i!=0){
                hashset.erase(s[i-1]);
            }
            while(right<s.size()&&hashset.find(s[right])==hashset.end()){
                hashset.insert(s[right]);
                right++;
            }
            cnt=max(cnt,right-i);
        }
        return cnt;
    }
};