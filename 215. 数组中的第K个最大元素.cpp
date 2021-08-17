215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

class Solution {
public:
    int quick_select(vector<int>& nums, int left, int right, int index){
        int pivot=random_partition(nums,left,right);
        if(pivot==index){
            return nums[pivot];
        }
        else{
            return pivot>index?quick_select(nums,left,pivot-1,index):quick_select(nums,pivot+1,right,index);
        }
    }
    int random_partition(vector<int>& nums, int left, int right){
        int pivot=rand()%(right-left+1)+left;
        swap(nums[pivot],nums[right]);
        return partition(nums,left,right);
    }
    int partition(vector<int>& nums, int left, int right){
        int i=left-1;
        for(int j=left;j!=right;j++){
            if(nums[j]<=nums[right]){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[i+1],nums[right]);
        return i+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quick_select(nums,0,nums.size()-1,nums.size()-k);
    }
};