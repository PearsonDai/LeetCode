4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        int totalLeft = (m + n + 1) / 2;
        int left = 0, right = m;
        while(left < right){
            int i = (left + right + 1) / 2;
            int j = totalLeft - i;
            if(nums1[i - 1] > nums2[j]){
                right = i - 1;
            }
            else{
                left = i;
            }
        }
        int i = left;
        int j = totalLeft - i;
        int left_max1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int right_min1 = (i == m) ? INT_MAX : nums1[i];
        int left_max2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int right_min2 = (j == n) ? INT_MAX : nums2[j];
        if((m + n) % 2 == 1){
            return max(left_max1, left_max2);
        }
        else{
            return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0;
        }
    }
};