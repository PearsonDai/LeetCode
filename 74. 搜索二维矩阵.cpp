74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 

示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0,right=m-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]<target) left=mid+1;
            else right=mid-1;
        }
        if(m>1&&left==0) return false;
        int row = (m==1)?0:left-1;
        left=0;
        right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};