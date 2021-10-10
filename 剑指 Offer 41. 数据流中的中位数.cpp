剑指 Offer 41. 数据流中的中位数
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制：

最多会对 addNum、findMedian 进行 50000 次调用。
注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> min_que;
    priority_queue<int, vector<int>, greater<int>> max_que;

    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(min_que.empty() || min_que.top() >= num){
            min_que.push(num);
            if(min_que.size() - max_que.size() > 1){
                max_que.push(min_que.top());
                min_que.pop();
            }
        }
        else{
            max_que.push(num);
            if(max_que.size() > min_que.size()){
                min_que.push(max_que.top());
                max_que.pop();
            }
        }
    }
    
    double findMedian() {
        if(max_que.size() < min_que.size()){
            return min_que.top();
        }
        else{
            return (min_que.top() + max_que.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */