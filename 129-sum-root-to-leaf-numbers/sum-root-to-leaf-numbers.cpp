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
    int ans;
    void helper(TreeNode* root, int v){
        if(!root) return;
        if(!root->left && !root->right){
            int x = v*10+root->val;
            ans += x;
            return;
        }
        v = v*10;
        helper(root->left, v+root->val);
        helper(root->right, v+root->val);
        v = v/10;
    }
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
};