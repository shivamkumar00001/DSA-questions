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
    TreeNode* prev = nullptr;
    void helper(TreeNode* & root , TreeNode* &first ,TreeNode* &second){
        if(root == NULL) return ;
        helper(root->left , first , second);

        if(prev && root->val<prev->val){
            if(!first) first = prev;
            second = root;
        }

        prev = root;
        helper(root->right , first , second);


    }
    void recoverTree(TreeNode* root) {
       TreeNode* first = nullptr;
       TreeNode* second = nullptr;
       helper(root , first , second);
       swap(first->val,second->val);
    }
};