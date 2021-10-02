51. N 皇后
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例 1：


输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]]
 

提示：

1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

class Solution {
public:
    bool isValid(vector<string>& temp, int row, int col, int n){
        for(int i = 0; i < row; i++){
            if(temp[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >=0 && j >=0; i--, j--){
            if(temp[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(temp[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<string>>& res, vector<string>& temp, int row, int n){
        if(row == n){
            res.push_back(temp);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isValid(temp, row, col, n)){
                temp[row][col] = 'Q';
                dfs(res, temp, row + 1, n);
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        dfs(res, temp, 0, n);
        return res;
    }
};