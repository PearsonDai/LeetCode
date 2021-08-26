剑指 Offer 27. 二叉树的镜像
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
 

限制：

0 <= 节点个数 <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//层序遍历+队列
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        TreeNode* curr=root;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            curr=que.front();
            que.pop();
            TreeNode* left=curr->left;
            TreeNode* right=curr->right;
            curr->left=right;
            curr->right=left;
            if(right!=nullptr) que.push(right);
            if(left!=nullptr) que.push(left);
        }
        return root;
    }
};