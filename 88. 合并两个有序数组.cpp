88. 合并两个有序数组
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

 

示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]

示例 2：

输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]

/*
方法一，先合并后sort排序
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;++i){
            nums1[m+i]=nums2[i];
        }  
        sort(nums1.begin(),nums1.end());
    }
};
*/

//方法二,逆向的双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,tail=m+n-1,curr;
        while(p1>=0||p2>=0){
            if(p1==-1){
                curr=nums2[p2--];
            }
            else if(p2==-1){
                curr=nums1[p1--];
            }
            else if(nums1[p1]<nums2[p2]){
                curr=nums2[p2--];
            }
            else{
                curr=nums1[p1--];
            }
            nums1[tail--]=curr;
        }
    }
};