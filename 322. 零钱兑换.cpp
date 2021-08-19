322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2
//贪心算法（暴力算法）+剪枝
class Solution {
public:
    void dfs(vector<int>& coins, int amount, int c_index, int count, int& ans){
        if(amount==0){
            ans=min(ans,count);
            return;
        }
        if(c_index==coins.size()){
            return;
        }
        for(int k=amount/coins[c_index];k>=0&&k+count<ans;k--){
            dfs(coins,amount-k*coins[c_index],c_index+1,count+k,ans);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int ans=INT_MAX;
        sort(coins.rbegin(),coins.rend());
        dfs(coins,amount,0,0,ans);
        return ans==INT_MAX?-1:ans;
    }
};

//动态规划
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int tempMin=INT_MAX-1;
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j]){
                    tempMin=min(tempMin,dp[i-coins[j]]);
                }
            }
            dp[i]=1+tempMin;
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};