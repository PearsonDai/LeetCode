164. 最大间距
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        int maxVal = *max_element(nums.begin(), nums.end());
        int times = maxBit(maxVal);
        vector<int> buf(nums.size());
        int digit = 1;
        for(int i = 0; i < times; i++){
            vector<int> count(10, 0);
            for(int j = 0; j < n; j++){
                int tail = (nums[j] / digit) % 10;
                count[tail]++;
            }
            for(int j = 1; j < 10; j++){
                count[j] += count[j - 1];
            }
            for(int j = n - 1; j >= 0; j--){
                int tail = (nums[j] / digit) % 10;
                buf[count[tail] - 1] = nums[j];
                count[tail]--;
            }
            copy(buf.begin(), buf.end(), nums.begin());
            digit *= 10;
        }
        int res = 0;
        for(int i = 0; i < n - 1; i ++){
            res = max(res, nums[i + 1] - nums[i]);
        }
        return res;
    }
    int maxBit(int& num){
        if(num == 0) return 1;
        int digit = 0;
        while(num > 0){
            digit++;
            num /= 10;
        }
        return digit;
    }
};