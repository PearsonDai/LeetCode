204. 计数质数
统计所有小于非负整数 n 的质数的数量。

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0

//暴力枚举法的优化，只在[2,根号x]范围内找其因子。
class Solution {
public:
    bool isPrime(int n){
        if(n==2){
            return true;
        }
        for(int i=2;i*i<=n;++i){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if(n==0||n==1||n==2){
            return 0;
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isPrime(i)){
                cnt++;
            }
        }
        return cnt;
    }
};

//埃氏筛
class Solution {
public:
    int countPrimes(int n) {
        int resCnt=0;
        vector<int> isPrime(n,1);
        for(int i=2;i<n;++i){
            if(isPrime[i]==1){
                resCnt++;
                if((long long)i*i<n){
                    for(int j=i*i;j<n;j+=i){
                        isPrime[j]=0;
                    }
                }
            }
        }
        return resCnt;
    }
};