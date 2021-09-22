695. 岛屿的最大面积
给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

示例 1：


输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
输出：6
解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
示例 2：

输入：grid = [[0,0,0,0,0,0,0,0]]
输出：0
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] 为 0 或 1

class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int cnt){
        cnt++;
        visited[i][j] = true;
        for(int dir = 0; dir < 4; dir++){
            int x = i + directions[dir][0];
            int y = j + directions[dir][1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1 && visited[x][y] == false){
                cnt = max(cnt, dfs(grid, visited, x, y, cnt));
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ;j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    cnt = dfs(grid, visited, i, j, 0);
                    res = max(res, cnt);
                }
            }
        }
        return res; 
    }
};