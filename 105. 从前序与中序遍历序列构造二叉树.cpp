105. 从前序与中序遍历序列构造二叉树
给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。

示例 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
示例 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均无重复元素
inorder 均出现在 preorder
preorder 保证为二叉树的前序遍历序列
inorder 保证为二叉树的中序遍历序列

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
private:
    unordered_map<int,int> index;
public:
    TreeNode* treeMake(vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright){
        if(preleft>preright){
            return nullptr;
        }
        int pIndex=index[preorder[preleft]];
        TreeNode* root=new TreeNode(preorder[preleft]);
        root->left=treeMake(preorder,preleft+1,pIndex-inleft+preleft,inorder,inleft,pIndex-1);
        root->right=treeMake(preorder,pIndex-inleft+preleft+1,preright,inorder,pIndex+1,inright);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return nullptr;
        }
        int preleft=0,preright=preorder.size()-1;
        int inleft=0,inright=inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            index[inorder[i]]=i;
        }
        return treeMake(preorder,preleft,preright,inorder,inleft,inright);
    }
};