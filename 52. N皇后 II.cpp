52. N皇后 II
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

示例 1：

输入：n = 4
输出：2
解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：

输入：n = 1
输出：1

提示：

1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q') return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void dfs(int& res, vector<vector<char>>& board, int row){
        if(row == board.size()){
            res++;
            return;
        }
        for(int j = 0; j < board.size(); j++){
            if(isValid(board, row, j)){
                board[row][j] = 'Q';
                dfs(res, board, row + 1);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        dfs(res, board, 0);
        return res;
    }
};