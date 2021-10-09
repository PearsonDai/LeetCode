295. 数据流的中位数
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> que_min;
    priority_queue<int, vector<int>, greater<int>> que_max;
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(que_min.empty() || num <= que_min.top()){
            que_min.push(num);
            if(que_min.size() - que_max.size() > 1){
                que_max.push(que_min.top());
                que_min.pop();
            }
        }
        else{
            que_max.push(num);
            if(que_max.size() > que_min.size()){
                que_min.push(que_max.top());
                que_max.pop();
            }
        }
    }
    
    double findMedian() {
        if(que_min.size() > que_max.size()){
            return que_min.top();
        }
        return (que_min.top() + que_max.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */