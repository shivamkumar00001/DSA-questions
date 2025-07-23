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
    bool helper(TreeNode * root,long long &temp){
        if(!root) return true;
        bool x = helper(root->left,temp);
        if(temp>=root->val) return false;
        temp = root->val; 
        bool y =  helper(root->right,temp);
        return x && y;
    }
    bool isValidBST(TreeNode* root) {
        long long temp = LLONG_MIN;
        return helper(root,temp);
        
    }
};