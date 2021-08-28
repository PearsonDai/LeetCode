剑指 Offer 32 - II. 从上到下打印二叉树 II
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 

提示：

节点总数 <= 1000

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> que;
        que.push({root,1});
        int depth=1;
        while(!que.empty()){
            vector<int> temp;
            while(que.front().second==depth){
                root=que.front().first;
                que.pop();
                temp.push_back(root->val);
                if(root->left) que.push({root->left,depth+1});
                if(root->right) que.push({root->right,depth+1});
            }
            res.push_back(temp);
            depth++;
        }
        return res;
    }
};