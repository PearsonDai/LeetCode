149. 直线上最多的点数
给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。

示例 1：

输入：points = [[1,1],[2,2],[3,3]]
输出：3
示例 2：

输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出：4
 

提示：

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
points 中的所有点 互不相同

class Solution {
public:
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 3) return n;
        int res = 0;
        unordered_map<string, int> hashmap;
        for(int i = 0; i < n; i++){
            if(res >= n - i || res > n / 2){
                return res;
            }
            for(int j = i + 1; j < n; j++){
                int deltaX = points[j][0] - points[i][0];
                int deltaY = points[j][1] - points[i][1];
                int g = gcd(deltaX, deltaY);
                deltaX /= g;
                deltaY /= g;
                string str = to_string(deltaX) + "/" + to_string(deltaY);
                hashmap[str]++;
            }
            for(auto it : hashmap){
                res = max(res, it.second + 1);
            }
            hashmap.clear();
        }
        return res;
    }
};