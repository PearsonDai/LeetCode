106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

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
    unordered_map<int,int> hashmap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return nullptr;
        for(int i=0;i<inorder.size();i++){
            hashmap[inorder[i]]=i;
        }
        int left1=0,left2=0,right1=inorder.size()-1,right2=postorder.size()-1;
        TreeNode* root=dfs(inorder,left1,right1,postorder,left2,right2);
        return root;
    }
    TreeNode* dfs(vector<int>& inorder, int left1, int right1, vector<int>& postorder, int left2,int right2){
        if(left1>right1||left2>right2) return nullptr;
        int value=postorder[right2];
        TreeNode* root=new TreeNode(value);
        int idx=hashmap[value];
        root->left=dfs(inorder,left1,idx-1,postorder,left2,right2-right1+idx-1);
        root->right=dfs(inorder,idx+1,right1,postorder,right2-right1+idx,right2-1);
        return root;
    }
};