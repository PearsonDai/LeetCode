347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]

class Solution {
public:
    struct mycomparison{
        bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.second>rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++){
            hashmap[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pri_que;
        for(auto it=hashmap.begin();it!=hashmap.end();it++){
            pri_que.push(*it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};