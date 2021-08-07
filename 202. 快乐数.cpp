202. 快乐数
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。

示例 1：

输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

示例 2：

输入：n = 2
输出：false

//哈希集合
class Solution {
public:
    long pow2(int n){
        long res=0;
        while(n){
            int temp=n%10;
            res+=temp*temp;
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<long> hashset;
        hashset.insert(n);
        while(1){
            if(n==1){
                return true;
            }
            n=pow2(n);
            if(hashset.find(n)!=hashset.end()){
                return false;
            }
            else{
                hashset.insert(n);
            }
        }
        return false;
    }
};

//快慢指针
class Solution {
public:
    long pow2(int n){
        long res=0;
        while(n){
            int temp;
            temp=n%10;
            res+=temp*temp;
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int stepOneRunner=n;
        int stepTwoRunner=pow2(n);
        while(stepTwoRunner!=1&&stepTwoRunner!=stepOneRunner){
            stepOneRunner=pow2(stepOneRunner);
            stepTwoRunner=pow2(pow2(stepTwoRunner));
        }
        return stepTwoRunner==1;
    }
};