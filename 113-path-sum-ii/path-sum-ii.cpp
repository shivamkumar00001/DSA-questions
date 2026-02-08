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
    vector<vector<int>> ans;
    void helper( TreeNode* root, int targetSum, vector<int>v){
        if(!root) return;
        if(!root->left && !root->right){
            if(targetSum-root->val == 0) {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }

        v.push_back(root->val);
        helper(root->left, targetSum-root->val, v);
        helper(root->right, targetSum-root->val, v);
        v.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>v;
        helper(root, targetSum, v);
        return ans;
    }
};