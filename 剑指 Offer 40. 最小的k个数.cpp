剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0) return {};
        priority_queue<int, vector<int>, less<int>> pri_que;
        pri_que.push(arr[0]);
        for(int i=1;i<arr.size();i++){
            pri_que.push(arr[i]);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=pri_que.top();
            pri_que.pop();
        }
        return res;
    }
};