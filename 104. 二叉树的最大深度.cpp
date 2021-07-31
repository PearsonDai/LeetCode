104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

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
//深度优先
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

//迭代
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        int res=0;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int sz=Q.size();
            while(sz-->0){
                auto node=Q.front();
                Q.pop();
                if(node->left)Q.push(node->left);
                if(node->right)Q.push(node->right);
            }
            res++;
        }
        return res;
    }
};