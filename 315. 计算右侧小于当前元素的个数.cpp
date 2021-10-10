315. 计算右侧小于当前元素的个数
给你`一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例 1：

输入：nums = [5,2,6,1]
输出：[2,1,1,0] 
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素
示例 2：

输入：nums = [-1]
输出：[0]
示例 3：

输入：nums = [-1,-1]
输出：[0,0]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return {};
        }
        vector<int> res(n, 0);
        vector<int> indexes(n, 0);
        vector<int> temp(n, 0);

        for(int i = 0; i < n; i++){
            indexes[i] = i;
        }
        int left = 0, right = n - 1;
        mergeAndCountSmaller(res, left, right, nums, indexes, temp);
        return res;
    }

    void mergeAndCountSmaller(vector<int>& res, int left, int right, vector<int>& nums, vector<int>& indexes, vector<int>& temp){
        if(left == right){
            return;
        }
        int mid = left + (right - left) / 2;
        mergeAndCountSmaller(res, left, mid, nums, indexes, temp);
        mergeAndCountSmaller(res, mid + 1, right, nums, indexes, temp);
        if(nums[indexes[mid]] <= nums[indexes[mid + 1]]){
            return;
        }
        merge(res, left, right, mid, nums, indexes, temp);
    }

    void merge(vector<int>& res, int left, int right, int mid, vector<int>& nums, vector<int>& indexes, vector<int>& temp){
        for(int i = left; i <= right; i++){
            temp[i] = indexes[i];
        }
        int i = left, j = mid + 1;
        for(int k = left; k <= right; k++){
            if(i == mid + 1){
                indexes[k] = temp[j];
                j++;
            }
            else if(j == right + 1){
                indexes[k] = temp[i];
                res[temp[i]] += right -mid;
                i++;
            }
            else if(nums[temp[i]] <= nums[temp[j]]){
                indexes[k] = temp[i]; 
                res[temp[i]] += j - mid - 1;
                i++;
            }
            else{
                indexes[k] = temp[j];
                j++;
            }
        }
    }
};