17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]

class Solution {
private:
    unordered_map<char, string> phonemap={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
public:
    void backTrack(vector<string>& res, const unordered_map<char,string>& phonemap,string& digits, int index, string& combination){
        if(index==digits.size()){
            res.push_back(combination);
            return;
        }
        char digit=digits[index];
        const string& letters=phonemap.at(digit);
        for(const char& letter:letters){
            combination.push_back(letter);
            backTrack(res, phonemap, digits, index+1, combination);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()){
            return res;
        }
        string combination;
        backTrack(res,phonemap,digits,0,combination);
        return res;
    }
};