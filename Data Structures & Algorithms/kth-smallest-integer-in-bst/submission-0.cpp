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

    void dfs(TreeNode* r, vector<int>& inOrder ){
        if(r == nullptr) return ; 

        dfs(r->left, inOrder);

        inOrder.push_back(r->val);

        dfs(r->right, inOrder);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;
        dfs(root,inOrder);
        
        return inOrder[k-1];
    }
};
