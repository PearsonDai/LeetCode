剑指 Offer 12. 矩阵中的路径
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
 

提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
board 和 word 仅由大小写英文字母组成

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int wordIdx, vector<vector<bool>>& visited){
        if(board[i][j]!=word[wordIdx]) return false;
        if(wordIdx==word.size()-1) return true;
        visited[i][j]=true;
        bool res=false;
        vector<pair<int,int>> directions={
            {-1,0},
            {0,-1},
            {1,0},
            {0,1}
        };
        int rows=board.size();
        int cols=board[0].size();
        for(auto& dir:directions){
            int newi=i+dir.first;
            int newj=j+dir.second;
            if(newi>=0&&newi<rows&&newj>=0&&newj<cols){
                if(!visited[newi][newj]){
                    res=dfs(board,newi,newj,word,wordIdx+1,visited);
                    if(res==true) return true;
                }
            }
        }
        visited[i][j]=false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        int wordIdx=0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                bool flag=dfs(board,i,j,word,wordIdx,visited);
                if(flag==true) return true;
            }
        }
        return false;
    }
};