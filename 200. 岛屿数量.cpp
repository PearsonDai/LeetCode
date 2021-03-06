200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m=grid.size();
        int n=grid[0].size();
        grid[i][j]='0';
        if(i-1>=0&&grid[i-1][j]=='1')dfs(grid,i-1,j);
        if(i+1<m&&grid[i+1][j]=='1')dfs(grid,i+1,j);
        if(j-1>=0&&grid[i][j-1]=='1')dfs(grid,i,j-1);
        if(j+1<n&&grid[i][j+1]=='1')dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands_num=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands_num++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands_num;
    }
};