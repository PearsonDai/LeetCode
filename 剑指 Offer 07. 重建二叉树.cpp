剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

示例 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
示例 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

限制：

0 <= 节点个数 <= 5000

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
    unordered_map<int,int> hashmap;

    TreeNode* TreeMaker(vector<int>& preorder,int left1,int right1,vector<int>& inorder,int left2,int right2){
        if(left1>right1) return nullptr;
        int rootVal=preorder[left1];
        int Idx=hashmap[rootVal];
        TreeNode* root=new TreeNode(rootVal);
        root->left=TreeMaker(preorder,left1+1,Idx+left1-left2,inorder,left2,Idx-1);
        root->right=TreeMaker(preorder,Idx+left1-left2+1,right1,inorder,Idx+1,right2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        for(int i=0;i<inorder.size();i++){
            hashmap[inorder[i]]=i;
        }
        int left1=0,right1=preorder.size()-1;
        int left2=0,right2=inorder.size()-1;
        return TreeMaker(preorder,left1,right1,inorder,left2,right2);
    }
};