119. 杨辉三角 II
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:
输入: rowIndex = 3
输出: [1,3,3,1]

示例 2:
输入: rowIndex = 0
输出: [1]

示例 3:
输入: rowIndex = 1
输出: [1,1]

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res{1};
        vector<int> temp;
        for(int i=1;i<=rowIndex;++i){
            temp.resize(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;++j){
                temp[j]=res[j-1]+res[j];
            }
            res=temp;
        }
        return res;
    }
};

//优化方案
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[0]=1;
        for(int i=1;i<=rowIndex;++i){
            for(int j=i;j>0;--j){
                res[j]+=res[j-1];
            }
        }
        return res;
    }
};