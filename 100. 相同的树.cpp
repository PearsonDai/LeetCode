100. 相同的树
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1：
输入：p = [1,2,3], q = [1,2,3]
输出：true

示例 2：
输入：p = [1,2], q = [1,null,2]
输出：false

示例 3：
输入：p = [1,2,1], q = [1,1,2]
输出：false

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
//深度优先DFS
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)return true;
        else if((p==nullptr&&q!=nullptr)||(p!=nullptr&&q==nullptr))return false;
        if(p->val!=q->val){
            return false;
        }
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};
//广度优先BFS
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)return true;
        else if(p==nullptr||q==nullptr)return false;
        queue<TreeNode*> Q1,Q2;
        Q1.push(p);
        Q2.push(q);
        while(!Q1.empty()&&!Q2.empty()){
            TreeNode* node1=Q1.front();
            TreeNode* node2=Q2.front();
            if(node1->val!=node2->val)return false;
            Q1.pop();
            Q2.pop();
            TreeNode* left1=node1->left;
            TreeNode* right1=node1->right;
            TreeNode* left2=node2->left;
            TreeNode*right2=node2->right;
            if((left1==nullptr)^(left2==nullptr))return false;
            if((right1==nullptr)^(right2==nullptr))return false;
            if(left1!=nullptr){
                Q1.push(left1);
                Q2.push(left2);
            }
            if(right1!=nullptr){
                Q1.push(right1);
                Q2.push(right2);
            }
        }
        return Q1.empty()&&Q2.empty();
    }
};