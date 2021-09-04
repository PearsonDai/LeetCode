18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] ：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
 

提示：

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(nums[i]+nums[i+1]>target-(nums[i+2]+nums[i+3])) break;
            if(nums[i]+nums[n-3]<target-(nums[n-2]+nums[n-1])) continue;
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(nums[i]+nums[j]>target-(nums[j+1]+nums[j+2])) break;
                if(nums[i]+nums[j]<target-(nums[n-2]+nums[n-1])) continue;
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int left=j+1;
                int right=n-1;
                while(left<right){
                    if(nums[i]+nums[j]>target-(nums[left]+nums[right])){
                        right--;
                    }
                    else if(nums[i]+nums[j]<target-(nums[left]+nums[right])){
                        left++;
                    }
                    else{
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right&&nums[left]==nums[left-1]) left++;
                        while(left<right&&nums[right]==nums[right+1]) right--;
                    }
                }
            }
        }
        return res;
    }
};