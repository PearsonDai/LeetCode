5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"

//中心扩散法
class Solution {
public:
    pair<int,int> expandFromCentre(const string& s,int left, int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        return {left+1,right-1};
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2){
            return s;
        }
        int maxlen=1;
        int begin=0;
        for(int i=0;i<n;i++){
            auto [left1,right1]=expandFromCentre(s,i,i);
            auto [left2,right2]=expandFromCentre(s,i,i+1);
            if(right1-left1+1>maxlen){
                maxlen=right1-left1+1;
                begin=left1;
            }
            if(right2-left2+1>maxlen){
                maxlen=right2-left2+1;
                begin=left2;
            }
        }
        return s.substr(begin,maxlen);
    }
};

//动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2){
            return s;
        }
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int maxlen=1;
        int begin=0;
        for(int L=2;L<=n;L++){
            for(int i=0;i<n;i++){
                int j=i+L-1;
                if(j>=n){
                    break;
                }
                if(s[i]!=s[j]){
                    dp[i][j]=0;
                }
                else{
                    if(j-i<3){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]==1&&j-i+1>maxlen){
                    maxlen=j-i+1;
                    begin=i;
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};