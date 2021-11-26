460. LFU 缓存
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
void put(int key, int value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。

示例：

输入：
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
输出：
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

解释：
// cnt(x) = 键 x 的使用计数
// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
LFUCache lFUCache = new LFUCache(2);
lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lFUCache.get(1);      // 返回 1
                      // cache=[1,2], cnt(2)=1, cnt(1)=2
lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                      // cache=[3,1], cnt(3)=1, cnt(1)=2
lFUCache.get(2);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,1], cnt(3)=2, cnt(1)=2
lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                      // cache=[4,3], cnt(4)=1, cnt(3)=2
lFUCache.get(1);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,4], cnt(4)=1, cnt(3)=3
lFUCache.get(4);      // 返回 4
                      // cache=[3,4], cnt(4)=2, cnt(3)=3

提示：

0 <= capacity, key, value <= 104
最多调用 105 次 get 和 put 方法

进阶：你可以为这两种操作设计时间复杂度为 O(1) 的实现吗？

struct DLinkedNode {
    int key;
    int val;
    int freq;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode(int _key, int _val) : key(_key), val(_val), freq(1), pre(nullptr), next(nullptr) {}
};

struct DLinkedList {
    DLinkedNode* head;
    DLinkedNode* tail;
    DLinkedList(){
        head = new DLinkedNode(-1, -1);
        tail = new DLinkedNode(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
};

class LFUCache {
private:
    int maxSize;
    int currSize;
    int minFreq;
    unordered_map<int, DLinkedNode*> nodeMap;
    unordered_map<int, DLinkedList*> listMap;
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()){
            return -1;
        }
        DLinkedNode* node = nodeMap[key];
        removeNode(node);
        node->freq += 1;
        insertNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(maxSize == 0){
            return;
        }
        if(nodeMap.find(key) != nodeMap.end()){
            DLinkedNode* node = nodeMap[key];
            removeNode(node);
            node->val = value;
            node->freq += 1;
            insertNode(node);
        }
        else{
            if(currSize == maxSize){
                deleteNode();
                currSize--;
            }
            DLinkedNode* node = new DLinkedNode(key, value);
            minFreq = 1;
            insertNode(node);
            nodeMap[key] = node;
            currSize++;
        }
    }

    void removeNode(DLinkedNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        if(node->freq == minFreq && listMap[minFreq]->head->next == listMap[minFreq]->tail){
            minFreq++;
        }
    }

    void insertNode(DLinkedNode* node){
        int frequency = node->freq;
        if(listMap.find(frequency) == listMap.end()){
            listMap[frequency] = new DLinkedList();
        }
        DLinkedList* list = listMap[frequency];
        node->next = list->head->next;
        node->pre = list->head;
        node->next->pre = node;
        list->head->next = node;
    }

    void deleteNode(){
        DLinkedNode* last = listMap[minFreq]->tail->pre;
        last->pre->next = last->next;
        last->next->pre = last->pre;
        nodeMap.erase(last->key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */