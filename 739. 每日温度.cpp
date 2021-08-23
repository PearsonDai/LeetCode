739. 每日温度
请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> daysRes(n,0);
        stack<int> stk;
        int i=0;
        while(i<n){
            while(!stk.empty()&&temperatures[i]>temperatures[stk.top()]){
                int topIdx=stk.top();
                stk.pop();
                daysRes[topIdx]=i-topIdx;
            }
            stk.push(i++);
        }
        return daysRes;
    }
};