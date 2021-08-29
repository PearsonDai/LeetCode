剑指 Offer 34. 二叉树中和为某一值的路径
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
给定如下二叉树，以及目标和 target = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

提示：

节点总数 <= 10000

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
    void dfs(vector<vector<int>>&res, vector<int> curr, TreeNode* root, int target){
        if(root==nullptr){
            return;
        }
        curr.push_back(root->val);
        target-=root->val;
        if(root->left==nullptr&&root->right==nullptr&&target==0){
            res.push_back(curr);
            return;
        }
        dfs(res,curr,root->left,target);
        dfs(res,curr,root->right,target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        vector<int> curr;
        dfs(res,curr,root,target);
        return res;
    }
};