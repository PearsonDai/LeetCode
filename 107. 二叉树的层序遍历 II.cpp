107. 二叉树的层序遍历 II
给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层序遍历为：

[
  [15,7],
  [9,20],
  [3]
]

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
/*
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue<pair<int,TreeNode*>> que;
        stack<vector<int>> stk;
        int depth=1;;
        que.push({1,root});
        vector<int> temp;
        while(!que.empty()){
            while(que.front().first==depth){
                auto pairfront=que.front();
                que.pop();
                root=pairfront.second;
                temp.push_back(root->val);
                if(root->left) que.push({depth+1,root->left});
                if(root->right) que.push({depth+1,root->right});
            }
            stk.push(temp);
            temp.clear();
            depth++;
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
                root=Q.front().first;
                temp.push_back(root->val);
                Q.pop();
                if(root->left){
                    Q.push({root->left,depth+1});
                }
                if(root->right){
                    Q.push({root->right,depth+1});
                }
            }
            ans.push_back(temp);
            depth++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};