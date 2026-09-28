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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        vector<vector<int>> ans; 
        queue<TreeNode*> q; 
        q.push(root);

        while(!q.empty()){
            int numberNodeInLevel = q.size();
            vector<int> currentLevel;

            for(int i = 0; i < numberNodeInLevel; i++){
                TreeNode* tmp = q.front();
                q.pop();

                currentLevel.push_back(tmp->val);

                if(tmp->left != nullptr) q.push(tmp->left); 
                if(tmp->right != nullptr) q.push(tmp->right);
            }

            ans.push_back(currentLevel);
        }

        return ans;
    }
};
