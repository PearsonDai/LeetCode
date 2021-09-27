面试题 17.14. 最小K个数
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))

class Solution {
public:
    void quick_sort(vector<int>& arr, int l, int r, int k){
        if(l > r) return;
        int left = l, right = r;
        int key = rand() % (right - left + 1) + left;
        swap(arr[left], arr[key]);
        int pivot = arr[left];
        while(left < right){
            while(left < right && arr[right] >= pivot) right--;
            arr[left] = arr[right];
            while(left < right && arr[left] <= pivot) left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        if(left == k - 1) return;
        else if(left < k - 1) quick_sort(arr, left + 1, r, k);
        else quick_sort(arr, l, left - 1, k);
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;
        quick_sort(arr, l, r, k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};