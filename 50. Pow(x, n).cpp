50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 

提示：

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104

class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0.0;
        if(x==1||n==0) return 1.0;
        long N=n;
        double res=1.0;
        if(n<0){
            N=-N;
            x=1.0/x;
        }
        while(N>0){
            if(N%2==1) res*=x;
            x*=x;
            N>>=1;
        }
        return res;
    }
};