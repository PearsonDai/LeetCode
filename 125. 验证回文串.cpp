125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
示例 2:

输入: "race a car"
输出: false
解释："raceacar" 不是回文串

class Solution {
public:
    bool isPalindrome(string s) {
        int sz=s.size();
        if(sz==0)return true;
        int left=0,right=sz-1;
        while(left<=right){
            if(!isdigit(s[left])&&!isalpha(s[left])){
                left++;
                continue;
            }
            if(!isdigit(s[right])&&!isalpha(s[right])){
                right--;
                continue;
            }
            if(isdigit(s[left])&&isdigit(s[right])&&(s[left]==s[right])){
                left++;
                right--;
                continue;
            }
            if(isalpha(s[left])&&isalpha(s[right])&&(toupper(s[left])==toupper(s[right]))){
                left++;
                right--;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};