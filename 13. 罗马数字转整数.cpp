13. 罗马数字转整数
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

 

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.

方法三：建立查找表，最推荐该方法。
不用把‘‘CM’’非要当作一个整体看待，C比M小，则减去C的值，C比M大，则加上C的值。
class Solution {
private:
    unordered_map<char, int>charVal={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
public:
    int romanToInt(string s) {
        int ret=0;
        int strlen=s.length();
        for(int i=0;i<strlen;++i){
            if(i<strlen-1&&charVal[s[i]]<charVal[s[i+1]])
                ret-=charVal[s[i]];
            else
                ret+=charVal[s[i]];
        }
        return ret;
    }
};

方法二：迭代器
class Solution {
public:
    int romanToInt(string s) {
        int ret=0;
        auto it=s.begin();
        while(it!=s.end()){
            if(*it=='I'){
                if(*(it+1)=='V'){
                    ret+=4;
                    it+=2;
                }
                else if(*(it+1)=='X'){
                    ret+=9;
                    it+=2;
                }
                else{
                    ret+=1;
                    it+=1;
                }
            }
            else if(*it=='X'){
                if(*(it+1)=='L'){
                    ret+=40;
                    it+=2;
                }
                else if(*(it+1)=='C'){
                    ret+=90;
                    it+=2;
                }
                else{
                    ret+=10;
                    it+=1;
                }
            }
            else if(*it=='C'){
                if(*(it+1)=='D'){
                    ret+=400;
                    it+=2;
                }
                else if(*(it+1)=='M'){
                    ret+=900;
                    it+=2;
                }
                else{
                    ret+=100;
                    it+=1;
                }
            }
            else{
                if(*it=='V'){
                    ret+=5;
                    ++it;
                }
                else if(*it=='L'){
                    ret+=50;
                    ++it;
                }
                else if(*it=='D'){
                    ret+=500;
                    ++it;
                }
                else if(*it=='M'){
                    ret+=1000;
                    ++it;
                }
            }
        }
        return ret;
    }
};

方法一，传统while循环+分支判断语句
class Solution {
public:
    int romanToInt(string s) {
        int ret=0;
        int strlen=s.length();
        int i=0;
        while(i<strlen){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    ret+=4;
                    i+=2;
                }
                else if(s[i+1]=='X'){
                    ret+=9;
                    i+=2;
                }
                else{
                    ret+=1;
                    i+=1;
                }
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    ret+=40;
                    i+=2;
                }
                else if(s[i+1]=='C'){
                    ret+=90;
                    i+=2;
                }
                else{
                    ret+=10;
                    i+=1;
                }
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    ret+=400;
                    i+=2;
                }
                else if(s[i+1]=='M'){
                    ret+=900;
                    i+=2;
                }
                else{
                    ret+=100;
                    i+=1;
                }
            }
            else{
                if(s[i]=='V'){
                    ret+=5;
                    ++i;
                }
                else if(s[i]=='L'){
                    ret+=50;
                    ++i;
                }
                else if(s[i]=='D'){
                    ret+=500;
                    ++i;
                }
                else if(s[i]=='M'){
                    ret+=1000;
                    ++i;
                }
            }
        }
        return ret;
    }
};