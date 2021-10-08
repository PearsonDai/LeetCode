212. 单词搜索 II
给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例 1：


输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
输出：["eat","oath"]
示例 2：


输入：board = [["a","b"],["c","d"]], words = ["abcb"]
输出：[]
 

提示：

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] 是一个小写英文字母
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] 由小写英文字母组成
words 中的所有字符串互不相同

struct Trie {
    string word;
    Trie* children[26];
    Trie(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        word = "";
    }
};
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie* root = new Trie();
        for(int i = 0; i < words.size(); i++){
            Trie* curr = root;
            for(int j = 0; j < words[i].size(); j++){
                if(curr->children[words[i][j] - 'a'] == nullptr){
                    curr->children[words[i][j] - 'a'] = new Trie();
                }
                curr = curr->children[words[i][j] - 'a'];
            }
            curr->word = words[i];
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(res, root, board, i, j);
            }
        }
        return res;
    }

    void dfs(vector<string>& res, Trie* root, vector<vector<char>>& board, int row, int col){
        if(root == nullptr){
            return;
        }
        if(board[row][col] == '#' || root->children[board[row][col] - 'a'] == nullptr){
            return;
        }
        char ch = board[row][col];
        board[row][col] = '#';
        root = root->children[ch - 'a'];
        if(!root->word.empty()){
            res.push_back(root->word);
            root->word = "";
        }
        for(int i = 0; i < 4; i++){
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            if(newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size()){
                dfs(res, root, board, newRow, newCol);
            }
        }
        board[row][col] = ch;
    }
};