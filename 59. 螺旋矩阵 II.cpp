59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 20

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};

        int row=0,col=0;
        int dirIdx=0;
        matrix[0][0]=1;
        visited[0][0]=true;
        for(int i=2;i<=n*n;i++){
            int newRow=row+directions[dirIdx][0];
            int newCol=col+directions[dirIdx][1];
            //先通过试探，找到当下合适的方向
            if(newRow<0||newRow>=n||newCol<0||newCol>=n||visited[newRow][newCol]==true){
                dirIdx=(dirIdx+1)%4;
            }
            row=row+directions[dirIdx][0];
            col=col+directions[dirIdx][1];
            matrix[row][col]=i;
            visited[row][col]=true;
        }
        return matrix;
    }
};