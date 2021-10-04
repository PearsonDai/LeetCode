60. 排列序列
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

 

示例 1：

输入：n = 3, k = 3
输出："213"
示例 2：

输入：n = 4, k = 9
输出："2314"
示例 3：

输入：n = 3, k = 1
输出："123"
 

提示：

1 <= n <= 9
1 <= k <= n!

class Solution {
public:
    void dfs(string& res, vector<bool>& visited, int n, int& k){
        if(res.size() == n){
            k--;
            return;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                visited[i] = true;
                res.push_back(i + 1 + '0');
                dfs(res, visited, n, k);
                if(k == 0) return;
                res.pop_back();
                visited[i] = false;
            }
        }
    }
    string getPermutation(int n, int k) {
        string res = "";
        vector<bool> visited(n, false);
        dfs(res, visited, n, k);
        return res;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        k--;
        vector<int> factorial(n);
        factorial[0] = 1;
        for(int i = 1; i < n; i++){
            factorial[i] = factorial[i - 1] * i;
        }
        string nums;
        for(int i = 0; i < n; i++){
            nums.push_back(i + 1 + '0');
        }
        while(n > 0){
            int grpInterIdx = k / factorial[n - 1];
            int grpInnerIdx = k % factorial[n - 1];
            res.push_back(nums[grpInterIdx]);
            nums.erase(nums.begin() + grpInterIdx);
            n--;
            k = grpInnerIdx;
        }
        return res;
    }
};