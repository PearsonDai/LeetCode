102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

//一次让我欣喜若狂的AC！
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> Q;
        if(root==nullptr){
            return ans;
        }
        int depth=1;
        Q.push({root,1});
        while(!Q.empty()){
            vector<int> temp;
            while(Q.front().second==depth){
                TreeNode* node=Q.front().first;
                temp.push_back(node->val);
                Q.pop();
                if(node->left){
                    Q.push({node->left,depth+1});
                }
                if(node->right){
                    Q.push({node->right,depth+1});
                }
            }
            ans.push_back(temp);
            depth++;
        }
        return ans;
    }
};