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
    int mini = INT_MAX;
    TreeNode* prev = nullptr;
    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return 0;

        minDiffInBST( root->left );
        
        if(prev) {
            mini = min(mini, root->val-prev->val);
        }
        prev = root;
        minDiffInBST(root->right);

        return mini;
    }
};