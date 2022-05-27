class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        int n = array.size();
        vector<int> dp(n, 0);
        dp[0] = array[0];
        int left = 0, right = 0;
        int resl = 0, resr = 0;
        int maxsum = array[0];
        for(int i = 1; i < n; i++){
            right++;
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            if(dp[i] > dp[i - 1] + array[i]){
                left = i;
            }
            if(dp[i] > maxsum || (dp[i] == maxsum && (right - left + 1) > (resr - resl + 1))){
                resl = left;
                resr = right;
                maxsum = dp[i];
            }
        }
        vector<int> res;
        for(int i = resl; i <= resr; i++){
            res.push_back(array[i]);
        }
        return res;
    }
};
