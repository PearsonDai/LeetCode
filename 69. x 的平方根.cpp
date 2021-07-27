69. x 的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

//二分查找
class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x,res=-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if((long long)mid*mid<=x){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};
/*
//自己写的方法，从头至尾搜查是否相等，太慢了
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return x;
        for(int i=1;i<x;++i){
            if(x/i>=i&&(x/(i+1)<i+1)){
                return i;
            }
        }
        return x;
    }
};
*/