208. 实现 Trie (前缀树)
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

示例：

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
 

提示：

1 <= word.length, prefix.length <= 2000
word 和 prefix 仅由小写英文字母组成
insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次

class Trie {
public:
    bool isword;
    Trie* children[26];
    /** Initialize your data structure here. */
    Trie() {
        Trie* root = this;
        root->isword = false;
        for(int i = 0; i < 26; i++){
            root->children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(char& ch: word){
            if(root->children[ch - 'a'] == nullptr){
                root->children[ch - 'a'] = new Trie();
            }
            root = root->children[ch - 'a'];
        }
        root->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        return dfs(root, word, 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        return dfs2(root, prefix, 0);
    }

    bool dfs(Trie* root, string word, int index){
        if(root == nullptr){
            return false;
        }
        if(index >= word.size()){
            return root->isword;
        }
        char ch = word[index];
        return dfs(root->children[ch - 'a'], word, index + 1);
    }

    bool dfs2(Trie* root, string prefix, int index){
        if(root == nullptr){
            return false;
        }
        if(index >= prefix.size()){
            return true;
        }
        char ch = prefix[index];
        return dfs2(root->children[ch - 'a'], prefix, index + 1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 class Trie {
public:
    bool isword;
    Trie* children[26];
    /** Initialize your data structure here. */
    Trie() {
        Trie* root = this;
        root->isword = false;
        for(int i = 0; i < 26; i++){
            root->children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(char& ch: word){
            if(root->children[ch - 'a'] == nullptr){
                root->children[ch - 'a'] = new Trie();
            }
            root = root->children[ch - 'a'];
        }
        root->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        root = searchPrefix(root, word);
        return root != nullptr && root->isword == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        root = searchPrefix(root, prefix);
        return root != nullptr;
    }
    
    Trie* searchPrefix(Trie* root, string prefix){
        for(char& ch : prefix){
            if(root->children[ch - 'a'] == nullptr){
                return nullptr;
            }
            root = root->children[ch - 'a'];
        }
        return root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */