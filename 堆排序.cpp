class Solution {
public:
    void down(vector<int>& nums, int idx, int n){
        int parentIdx = idx, childIdx = 2 * parentIdx + 1;
        while(childIdx < n){
            if(childIdx + 1 < n && nums[childIdx] < nums[childIdx + 1]){
                childIdx++;
            }
            if(nums[parentIdx] < nums[childIdx]){
                std::swap(nums[parentIdx], nums[childIdx]);
            }
            parentIdx = childIdx;
            childIdx = 2 * parentIdx + 1;
        }
    }
    void heap_sort(vector<int>& nums){
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            std::swap(nums[0], nums[i]);
            down(nums, 0, i);
        }
    }
    void build_heap(vector<int>& nums){
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; i--){
            down(nums, i, n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        build_heap(nums);
        heap_sort(nums);
        return nums;
    }
};
