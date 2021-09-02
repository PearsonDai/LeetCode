剑指 Offer 60. n个骰子的点数
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:

输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
 

限制：

1 <= n <= 11

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6,1.0/6.0);
        for(int i=2;i<=n;i++){
            //apply for one vector for representing [i*1,i*6]
            vector<double> temp(5*i+1,0);
            for(int j=0;j<dp.size();j++){
                for(int k=0;k<6;k++){
                    temp[j+k]+=dp[j]/6.0;
                }
            }
            dp=temp;
        }
        return dp;
    }
};

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(n+1,vector<double>(6*n+1,0.0));
        for(int j=1;j<=6;j++){
            dp[1][j]=1.0/6.0;
        }
        for(int i=2;i<=n;i++){
            for(int j=(i-1);j<=(i-1)*6;j++){
                for(int k=1;k<=6;k++){
                    dp[i][j+k]+=dp[i-1][j]/6.0;
                }
            }
        }
        vector<double> res;
        for(int i=n;i<=6*n;i++){
            res.push_back(dp[n][i]);
        }
        return res;
    }
};