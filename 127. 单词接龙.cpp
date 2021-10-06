127. 单词接龙
字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：

序列中第一个单词是 beginWord 。
序列中最后一个单词是 endWord 。
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典 wordList 中的单词。
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。

 
示例 1：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
示例 2：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。
 

提示：

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有字符串 互不相同

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> strSet(wordList.begin(), wordList.end());
        if(strSet.find(endWord) == strSet.end()) return 0;
        unordered_map<string, int> visitedMap;
        visitedMap.insert({beginWord, 1});
        queue<string> que;
        que.push(beginWord);
        while(!que.empty()){
            string word = que.front();
            que.pop();
            int path = visitedMap[word];
            for(int i = 0; i < word.size(); i++){
                char ch = word[i];
                for(int j = 0; j < 26; j++){ 
                    word[i] = j + 'a';
                    if(word == endWord) return path + 1;
                    else if(strSet.find(word) != strSet.end() && visitedMap.find(word) == visitedMap.end()){
                        visitedMap[word] = path + 1;
                        que.push(word);
                    }
                    word[i] = ch;
                }
            }
        }
        return 0;
    }
};