309. 最佳买卖股票时机含冷冻期
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //f0:第i天结束之后持有股票的累计最大收益
        int f0=-prices[0];
        //f1:第i天结束之后不持有股票，且处于冷冻期的累计最大收益
        int f1=0;
        //f2:第i天结束之后不持有股票，且不处于冷冻期的累计最大收益
        int f2=0;
        for(int i=1;i<prices.size();i++){
            int tempF0=max(f0,f2-prices[i]);
            int tempF1=f0+prices[i];
            int tempF2=max(f1,f2);
            f0=tempF0;
            f1=tempF1;
            f2=tempF2;
        }
        return max(f0,max(f1,f2));
    }
};