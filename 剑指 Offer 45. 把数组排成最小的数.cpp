剑指 Offer 45. 把数组排成最小的数
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
 

提示:

0 < nums.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

class Solution {
public:
    string minNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> strs;
        for(int& num:nums){
            strs.push_back(to_string(num));
        }
        quick_sort(strs,0,n-1);
        string res;
        for(string& str:strs){
            res+=str;
        }
        return res;
    }
    void quick_sort(vector<string>& strs, int left, int right){
        if(left<right){
            int mid=get_mid(strs,left,right);
            quick_sort(strs,left,mid-1);
            quick_sort(strs,mid+1,right);
        }
    }
    int get_mid(vector<string>& strs, int left, int right){
        string pivot=strs[left];
        while(left<right){
            while(strs[right]+pivot>=pivot+strs[right]&&left<right) right--;
                strs[left]=strs[right];
            while(strs[left]+pivot<=pivot+strs[left]&&left<right) left++;
                strs[right]=strs[left];
        }
        strs[left]=pivot;
        return left;
    }
};
//lambda
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto& num:nums){
            strs.push_back(to_string(num));
        }
        sort(strs.begin(),strs.end(),[](string& x, string& y){return x+y<y+x;});
        string res;
        for(string& str:strs){
            res+=str;
        }
        return res;
    }
};