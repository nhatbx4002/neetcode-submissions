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
    int ans = 0;

    void solve(TreeNode* r, int maxValueOfPath){
        if(r == nullptr) return ; 

        if(r->val >= maxValueOfPath) ans++;

        solve(r->left, r->val >= maxValueOfPath ? r->val : maxValueOfPath);
        solve(r->right, r->val >= maxValueOfPath ? r->val : maxValueOfPath);

        return ;
    }

    int goodNodes(TreeNode* root) {
        solve(root, root->val);

        return ans;
    }
};
