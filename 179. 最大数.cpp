179. 最大数
给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"
示例 3：

输入：nums = [1]
输出："1"
示例 4：

输入：nums = [10]
输出："10"
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 109

class Solution {
public:
    static bool cmp(int& a, int& b){
        string stra = to_string(a);
        string strb = to_string(b);
        return stra + strb > strb + stra;
    }
    string largestNumber(vector<int>& nums) {
        string res = "";
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]==0) return "0";
        for(int& num : nums){
            res+=to_string(num);
        }
        return res;
    }
};