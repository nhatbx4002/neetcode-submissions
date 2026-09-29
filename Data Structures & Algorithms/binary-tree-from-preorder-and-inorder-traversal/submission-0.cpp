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

    unordered_map<int,int> inIdx;
    int preI = 0;
    TreeNode* build(vector<int>& preOrder,int l,int r){
        if(l > r) return nullptr;

        int v = preOrder[preI++];
        TreeNode* node = new TreeNode(v);
        int m = inIdx[v];
        node->left = build(preOrder,l,m-1);
        node->right = build(preOrder,m+1,r);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0 ; i < inorder.size(); i++){
            inIdx[inorder[i]] = i;
        }

        return build(preorder,0,preorder.size()-1);
    }
};
