剑指 Offer 13. 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

//DFS
class Solution {
public:
    int digitSum(int m){
        int sum=0;
        while(m){
            sum+=m%10;
            m/=10;
        }
        return sum;
    }
    void dfs(vector<vector<bool>>& ans, vector<vector<bool>>& visited, int i, int j, int& k){
        if(i<0||i>=ans.size()||j<0||j>=ans[0].size()){
            return;
        }
        if(visited[i][j]){
            return;
        }
        visited[i][j]=true;
        int totSum=digitSum(i)+digitSum(j);
        if(totSum<=k){
            ans[i][j]=true;
            dfs(ans,visited,i+1,j,k);
            dfs(ans,visited,i,j+1,k);
        }
        dfs(ans,visited,i-1,j,k);
        dfs(ans,visited,i,j-1,k);
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> ans(m,vector<bool>(n,false));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(ans,visited,0,0,k);
        int cntRes=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]){
                    cntRes++;
                }
            }
        }
        return cntRes;
    }
};