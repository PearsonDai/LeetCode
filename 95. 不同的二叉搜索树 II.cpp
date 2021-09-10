95. 不同的二叉搜索树 II
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。

示例 1：


输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 8

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
    vector<TreeNode*> dfs(int low, int high){
        if(low>high){
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for(int i=low;i<=high;i++){
            vector<TreeNode*> leftTrees=dfs(low,i-1);
            vector<TreeNode*> rightTrees=dfs(i+1,high);
            for(auto left:leftTrees){
                for(auto right:rightTrees){
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res=dfs(1,n);
        return res;
    }
};