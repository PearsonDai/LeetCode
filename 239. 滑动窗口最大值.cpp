239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.first < b.first;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pri_que;
        for(int i = 0; i < k; i++){
            pri_que.push({nums[i], i});
        }
        res.push_back(pri_que.top().first);
        for(int i = 1; i + k - 1 < sz; i++){
            pri_que.push({nums[i + k - 1], i + k - 1});
            while(pri_que.top().second < i){
                pri_que.pop();
            }
            int temp = pri_que.top().first;
            res.push_back(temp);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        deque<int> que;
        for(int i = 0; i < k; i++){
            while(!que.empty() && nums[que.back()] < nums[i]){
                que.pop_back();
            }
            que.push_back(i);
        }
        res.push_back(nums[que.front()]);
        for(int i = k; i < n; i++){
            while(!que.empty() && nums[que.back()] < nums[i]){
                que.pop_back();
            }
            que.push_back(i);
            if(que.front() == i - k){
                que.pop_front();
            }
            res.push_back(nums[que.front()]);
        }
        return res;
    }
};