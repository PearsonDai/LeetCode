剑指 Offer 37. 序列化二叉树
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

示例：

输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]

注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

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
            TreeNode* root = que.front();
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
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]"){
            return nullptr;
        }
        data = data.substr(1, data.size() - 2);
        vector<string> strVec;
        string str = "";
        for(char& ch : data){
            if(ch != ','){
                str += ch;
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
// Codec codec;
// codec.deserialize(codec.serialize(root));