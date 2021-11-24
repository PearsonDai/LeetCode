542. 01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1：

输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]
示例 2：

输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
mat 中至少有一个 0 

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> que;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    que.push({i, j});
                }
            }
        }
        int sz = que.size();
        int step = 0;
        while(sz > 0){
            auto [i, j] = que.front();
            que.pop();
            mat[i][j] = step;
            sz--;
            for(int idx = 0; idx < 4; idx++){
                int newI = i + dir[idx][0];
                int newJ = j + dir[idx][1];
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && visited[newI][newJ] == false){
                    visited[newI][newJ] = true;
                    que.push({newI, newJ});
                }
            }
            if(sz == 0){
                sz = que.size();
                step++;
            }
        }
        return mat;
    }
};