101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

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
//递归，定义两个指针p和q
class Solution {
public:
    bool check(TreeNode *p, TreeNode *q){
        if(!p&&!q)return true;
        if(!p||!q)return false;
        return (p->val==q->val)&&check(p->left,q->right)&&check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};

//迭代
class Solution {
public:
    bool check(TreeNode* u,TreeNode* v){
        queue<TreeNode*>Q;
        Q.push(u);
        Q.push(v);
        while(!Q.empty()){
            u=Q.front();
            Q.pop();
            v=Q.front();
            Q.pop();
            if(!u&&!v)continue;
            if(!u||!v)return false;
            if(u->val!=v->val)return false;
            Q.push(u->left);
            Q.push(v->right);

            Q.push(u->right);
            Q.push(v->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};