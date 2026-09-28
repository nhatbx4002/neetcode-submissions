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
    map<int, vector<int>> res;

    void solve(TreeNode* r, int lv) {
        if (r == nullptr) return;

        res[lv].push_back(r->val);

        solve(r->left, lv + 1);
        solve(r->right, lv + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        solve(root, 1);

        vector<vector<int>> ans;
        for (auto& pair : res) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
