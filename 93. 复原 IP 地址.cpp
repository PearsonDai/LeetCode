93. 复原 IP 地址
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

提示：

0 <= s.length <= 3000
s 仅由数字组成

class Solution {
public:
    bool isValid(string& s, int start, int end){
        if(start>end){
            return false;
        }
        if(s[start]=='0'&&start!=end){
            return false;
        }
        int x=0;
        for(int i=start;i<=end;i++){
            if(!isdigit(s[i])){
                return false;
            }
            x=x*10+s[i]-'0';
            if(x>255) return false;
        }
        return true;
    }
    void dfs(vector<string>& res, string& s, string& temp, int start, int segId){
        if(segId==3){
            if(isValid(s,start,s.size()-1)){
                temp.push_back('.');
                temp+=s.substr(start,s.size()-start);
                res.push_back(temp);
                temp.erase(temp.size()-(s.size()-start),s.size()-start);
                temp.pop_back();
            }
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isValid(s,start,i)){
                if(segId!=0) temp.push_back('.');
                temp+=s.substr(start,i-start+1);
                dfs(res,s,temp,i+1,segId+1);
                temp.erase(temp.size()-(i-start+1),i-start+1);
                if(segId!=0) temp.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4||s.size()>12) return {};
        vector<string> res;
        string temp;
        dfs(res,s,temp,0,0);
        return res;
    }
};