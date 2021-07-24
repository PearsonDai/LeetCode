20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true

//模拟栈
class Solution {
private:
    unordered_map<char, char>brackets={
        {'(',')'},
        {'[',']'},
        {'{','}'},
    };
public:
    bool isValid(string s) {
        int len=s.size();
        if(len==0)return true;
        int i=1;
        string s_copy;
        s_copy.push_back(s[0]);
        while(i<len){
            if(brackets[s_copy.back()]==s[i]){
                s_copy.pop_back();
                ++i;
            }
            else{
                if(s[i]=='('||s[i]=='['||s[i]=='{'){
                    s_copy.push_back(s[i]);
                    ++i;
                }
                else{
                    return false;
                }
            }
        }
        if(s_copy.empty())return true;
        else return false;
    }
};
//使用真正的栈数据结构
/*
class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        if(len%2==1)return false;
        unordered_map<char, char>brackets={
            {')','('},
            {']','['},
            {'}','{'},
        };
        stack<char> stk;
        for(char ch:s){
            if(brackets.count[ch]){
                if(stk.empty()||stk.top()!=brackets[ch])
                    return false;
                stk.pop();
            else 
                stk.push(ch);
            }
        return stk.empty();
        }
    }
};
*/