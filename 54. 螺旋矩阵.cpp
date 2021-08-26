54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return {};
        int rows=matrix.size(),cols=matrix[0].size();
        int total=rows*cols;
        vector<int> res(total);
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int row=0,col=0,dirIdx=0;
        for(int i=0;i<total;i++){
            res[i]=matrix[row][col];
            visited[row][col]=true;
            int newRow=row+directions[dirIdx][0];
            int newCol=col+directions[dirIdx][1];
            if(newRow<0||newRow>=rows||newCol<0||newCol>=cols||visited[newRow][newCol]==true){
                dirIdx=(dirIdx+1)%4;
            }
            row+=directions[dirIdx][0];
            col+=directions[dirIdx][1];
        }
        return res;
    }
};