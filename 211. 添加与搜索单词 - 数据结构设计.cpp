211. 添加与搜索单词 - 数据结构设计
请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 WordDictionary ：

WordDictionary() 初始化词典对象
void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
 

示例：

输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]

解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

提示：

1 <= word.length <= 500
addWord 中的 word 由小写英文字母组成
search 中的 word 由 '.' 或小写英文字母组成
最多调用 50000 次 addWord 和 search

class WordDictionary {
public:
    bool isword;
    WordDictionary* children[26];
    /** Initialize your data structure here. */
    WordDictionary() {
        isword = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
    
    void addWord(string word) {
        WordDictionary* root = this;
        for(auto& ch : word){
            if(root->children[ch - 'a'] == nullptr){
                root->children[ch - 'a'] = new WordDictionary();
            }
            root = root->children[ch - 'a'];
        }
        root->isword = true;
    }
    
    bool search(string word) {
        WordDictionary* root = this;
        return dfs(root, word, 0);
    }

    bool dfs(WordDictionary* root, string word, int index){
        if(root == nullptr){
            return false;
        }
        if(index >= word.size()){
            return root->isword;
        }
        char ch = word[index];
        if(isalpha(ch)){
            return dfs(root->children[ch - 'a'], word, index + 1);
        }
        else{
            for(auto& node : root->children){
                if(node != nullptr && dfs(node, word, index + 1)){
                    return true;
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */