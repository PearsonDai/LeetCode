剑指 Offer 28. 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false

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
//迭代法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()){
            TreeNode* leftNode=que.front();
            que.pop();
            TreeNode* rightNode=que.front();
            que.pop();
            if(leftNode==nullptr&&rightNode==nullptr) continue;
            if(leftNode==nullptr||rightNode==nullptr||leftNode->val!=rightNode->val) return false;
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};

//递归法
class Solution {
public:
    bool check(TreeNode* leftNode, TreeNode* rightNode){
        if(leftNode==nullptr&&rightNode==nullptr) return true;
        if(leftNode==nullptr||rightNode==nullptr||leftNode->val!=rightNode->val) return false;
        return check(leftNode->left,rightNode->right)&&check(leftNode->right,rightNode->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return check(root->left,root->right);
    }
};