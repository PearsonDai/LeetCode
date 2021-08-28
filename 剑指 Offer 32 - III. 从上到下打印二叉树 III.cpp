剑指 Offer 32 - III. 从上到下打印二叉树 III
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
  [20,9],
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
        deque<pair<TreeNode*,int>> deq;
        deq.push_back({root,1});
        int depth=1;
        vector<vector<int>> res;
        while(!deq.empty()){
            vector<int> temp;
            while(depth%2==1&&deq.front().second==depth){
                root=deq.front().first;
                deq.pop_front();
                temp.push_back(root->val);
                if(root->left) deq.push_back({root->left,depth+1});
                if(root->right) deq.push_back({root->right,depth+1}); 
            }
            while(depth%2==0&&deq.back().second==depth){
                root=deq.back().first;
                deq.pop_back();
                temp.push_back(root->val);
                if(root->right) deq.push_front({root->right,depth+1});
                if(root->left) deq.push_front({root->left,depth+1});
            }
            res.push_back(temp);
            depth++;
        }
        return res;
    }
};