85. 最大矩形
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例 1：


输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = [["0"]]
输出：0
示例 4：

输入：matrix = [["1"]]
输出：1
示例 5：

输入：matrix = [["0","0"]]
输出：0
 

提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'

class Solution {
public:
    int partMaximal(vector<int>& heights){
        int res = 0;
        int n = heights.size();
        stack<int> stk;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int topIdx = stk.top();
                stk.pop();
                int width = i;
                if(!stk.empty()) width = i - stk.top() - 1;
                res = max(res, width * heights[topIdx]);
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int topIdx = stk.top();
            stk.pop();
            int width = n;
            if(!stk.empty()) width = n - stk.top() - 1;
            res = max(res, width * heights[topIdx]);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else{
                    heights[j] += 1;
                }
            }
            int partMax = partMaximal(heights);
            res = max(res, partMax);
        }
        return res;
    }
};