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
    bool same(TreeNode* a, TreeNode* b){
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr && b != nullptr || a != nullptr && b == nullptr) return false; 

        return (a->val == b->val) && same(a->left,b->left) && same(a->right,b->right);       
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return same(p,q);
    }
};
