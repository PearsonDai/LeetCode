144. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]

示例 5：
输入：root = [1,null,2]
输出：[1,2]

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
//递归
class Solution {
public:
    void preorder(TreeNode* root,vector<int>& ret){
        if(!root){
            return;
        }
        ret.push_back(root->val);
        preorder(root->left,ret);
        preorder(root->right,ret);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorder(root,ret);
        return ret;
    }
};
//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*>stk;
        while(root||!stk.empty()){
            while(root){
                res.push_back(root->val);
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            root=root->right;
        }
        return res;
    }
};