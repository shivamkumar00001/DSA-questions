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
    TreeNode* pred(TreeNode* root){
        // if(root->left == nullptr) return nullptr;
        TreeNode* pre = root->left;
        while(pre->right) pre = pre->right;
        return pre;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val == key){
            if(!root->left && !root->right) return nullptr;

            if(!root->left || !root->right){
                if(root->left) return root->left;
                else return root->right;
            }
            if(root->left && root->right){
                TreeNode* pre = pred(root);
                root->val = pre->val;
                root->left =deleteNode(root->left,pre->val);
                
            }
        }    
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);
        return root;
    }
};