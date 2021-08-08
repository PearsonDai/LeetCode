226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
//递归法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->left==nullptr&&root->right==nullptr){
            return root;
        }
        TreeNode *tempLeft=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(tempLeft);
        return root;
    }
};

//迭代法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *node=stk.top();
            stk.pop();
            swap(node->left,node->right);
            if(node->right)stk.push(node->right);
            if(node->left)stk.push(node->left);
        }
        return root;
    }
};