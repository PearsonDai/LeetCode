297. 二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

示例 1：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：

输入：root = [1,2]
输出：[1,2]
 

提示：

树中结点数在范围 [0, 104] 内
-1000 <= Node.val <= 1000

//层序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "[]";
        }
        string res = "[";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            root = que.front();
            que.pop();
            if(root != nullptr){
                res += to_string(root->val) + ",";
                que.push(root->left);
                que.push(root->right);
            }
            else{
                res += "null,";
            }
        }
        res.pop_back();
        res += ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") return nullptr;
        data = data.substr(1, data.size() - 2);
        vector<string> strVec;
        string str = "";
        for(int i = 0; i < data.size(); i++){
            if(data[i] != ','){
                str += data[i];
            }
            else{
                strVec.push_back(str);
                str.clear();
            }
        }
        strVec.push_back(str);
        TreeNode* root = new TreeNode(stoi(strVec[0]));
        queue<TreeNode*> que;
        que.push(root);
        int i = 1;
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(strVec[i] != "null"){
                node->left = new TreeNode(stoi(strVec[i]));
                que.push(node->left);
            }
            i++;
            if(strVec[i] != "null"){
                node->right = new TreeNode(stoi(strVec[i]));
                que.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//前序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root, string& res){
        if(root == nullptr){
            res += "null,";
        }
        else{
            res += to_string(root->val) + ",";
            dfs(root->left, res);
            dfs(root->right, res);
        }
    }
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "[]";
        }
        string res = "[";
        dfs(root, res);
        res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* strsToTree(queue<string>& que){
        if(que.front() == "null"){
            que.pop();
            return nullptr;
        }
        string str = que.front();
        que.pop();
        TreeNode* root = new TreeNode(stoi(str));
        root->left = strsToTree(que);
        root->right = strsToTree(que);
        return root;
    }
    TreeNode* deserialize(string data) {
        if(data == "[]") return nullptr;
        queue<string> que;
        data = data.substr(1, data.size() - 2);
        string str = "";
        for(int i = 0; i < data.size(); i++){
            if(data[i] != ','){
                str += data[i];
            }
            else{
                que.push(str);
                str.clear();
            }
        }
        que.push(str);
        return strsToTree(que);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));