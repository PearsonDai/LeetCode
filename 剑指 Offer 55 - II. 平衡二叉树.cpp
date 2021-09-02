剑指 Offer 55 - II. 平衡二叉树
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

限制：

0 <= 树的结点个数 <= 10000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        if(left==-1||right==-1||abs(left-right)>1){
            return -1;
        }
        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {
        return depth(root)>=0;
    }
};

class Solution {
public:
    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        int leftDepth=depth(root->left);
        int rightDepth=depth(root->right);
        return max(leftDepth,rightDepth)+1;
    }
    bool isBalanced(TreeNode* root) {
       if(root==nullptr) return true;
       int left=depth(root->left);
       int right=depth(root->right);
       return abs(left-right)<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }
};