329. 矩阵中的最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

示例 1：


输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。
示例 2：


输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4 
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
示例 3：

输入：matrix = [[1]]
输出：1
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

class Solution {
public:
    unordered_map<int, int> hashmap;
    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dfs(matrix, i, j, m, n));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int row, int col, int m, int n){
        if(hashmap.find(row * n + col) != hashmap.end()){
            return hashmap[row * n + col];
        }
        int path = 1;
        for(int i = 0; i < 4; i++){
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[row][col]){
                path = max(path, 1 + dfs(matrix, newRow, newCol, m, n));
            }
        }
        hashmap[row * n + col] = path;
        return hashmap[row * n + col];
    } 
};

class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dfs(matrix, i, j, m, n, memo));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int row, int col, int m, int n, vector<vector<int>>& memo){
        if(memo[row][col] != 0){
            return memo[row][col];
        }
        ++memo[row][col];
        for(int i = 0; i < 4; i++){
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[row][col]){
                memo[row][col] = max(memo[row][col], 1 + dfs(matrix, newRow, newCol, m, n, memo));
            }
        }
        return memo[row][col];
   } 
};