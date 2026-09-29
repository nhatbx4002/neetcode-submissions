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
    int maxSum = INT_MIN; 
    int solve(TreeNode* root){

        if(root == nullptr) return 0;

        int L = max(0,solve(root->left));
        int R = max(0,solve(root->right));

        int currentPath = root->val + L + R;
        maxSum = max(currentPath, maxSum);

        return root->val + max(L,R);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
