剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000

class Solution {
public:
    int mergeAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& temp){
        for(int i = left; i <= right; i++){
            temp[i] = nums[i];
        }
        int count = 0;
        int i = left, j = mid + 1;
        for(int k = left; k <= right; k++){
            if(i == mid + 1){
                nums[k] = temp[j];
                j++;
            }
            else if(j == right + 1){
                nums[k] = temp[i];
                i++;
            }
            else if(temp[i] <= temp[j]){
                nums[k] = temp[i];
                i++;
            }
            else{
                nums[k] = temp[j];
                j++;
                count += mid + 1 - i;
            }
        }
        return count;
    }
    
    int dfs(vector<int>& nums, int left, int right, vector<int>& temp){
        if(left == right){
            return 0;
        }
        int mid = left + (right - left) / 2;
        int leftPairs = dfs(nums, left, mid, temp);
        int rightPairs = dfs(nums, mid + 1, right, temp);
        if(nums[mid] <= nums[mid + 1]) return leftPairs + rightPairs;
        int crossPairs = mergeAndCount(nums, left, mid, right, temp);
        return leftPairs + rightPairs + crossPairs;
    }

    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if(len < 2){
            return 0;
        }
        vector<int> copy = nums;
        vector<int> temp(len);
        return dfs(copy, 0, len - 1, temp);
    }
};