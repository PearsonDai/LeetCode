68. 文本左右对齐
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

class Solution {
public:
    string blank(int n){
        string blk(n, ' ');
        return blk;
    }
    string join(vector<string>& words, int left, int right, string str){
        string res = "";
        int n = str.size();
        for(int i = left; i <= right; i++){
            res += words[i] + str;
        }
        res = res.substr(0, res.size() - n);
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int left = 0, right = 0;
        while(right < n){
            left = right;
            int sumLen = 0;
            while(right < n && sumLen + words[right].size() + right - left <= maxWidth){
                sumLen += words[right].size();
                right++;
            }
            if(right == n){
                string temp = join(words, left, right - 1, blank(1));
                temp += blank(maxWidth - temp.size());
                res.push_back(temp);
                return res;
            }
            int numWords = right - left;
            int numBlanks = maxWidth - sumLen;
            if(numWords == 1){
                string temp = words[left] + blank(numBlanks);
                res.push_back(temp);
            }
            else{
                int avgBlks = numBlanks / (numWords - 1);
                int extraBlks = numBlanks % (numWords - 1);
                string temp = join(words, left, left + extraBlks, blank(avgBlks + 1)); 
                temp += blank(avgBlks) + join(words, left + extraBlks + 1, right - 1, blank(avgBlks));
                res.push_back(temp);
            }
        }
        return res;
    }
};