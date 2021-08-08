219. 存在重复元素 II
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

//hashset维护k大小的滑动窗口
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashset;
        for(int i=0;i<nums.size();++i){
            if(hashset.find(nums[i])!=hashset.end()){
                return true;
            }
            hashset.insert(nums[i]);
            if(hashset.size()>k){
                hashset.erase(nums[i-k]);
            }
        }
        return false;
    }
};

//hashtable
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])!=map.end()){
                if(i-map[nums[i]]<=k){
                    return true;
                }
            }
            map[nums[i]]=i;
        }
        return false;
    }
};