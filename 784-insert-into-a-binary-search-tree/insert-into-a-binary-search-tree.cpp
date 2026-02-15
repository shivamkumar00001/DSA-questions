// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void helper( TreeNode* root, int val){
//         if(!root){
//             TreeNode* x= new TreeNode(val);
//             root = x;
//             return ;
//         }
//         if(root->val> val)
//         helper(root->left, val);
//         if(root->val<val)
//         helper(root->right, val);
//     }
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
        
//         helper( root, val);
//         return root;
//     }
// };



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
    void helper(TreeNode* &root,int val){
        if(root == NULL) {
            // TreeNode* temp = 
            root = new TreeNode(val);
            return ;
        }
        if(root->val>val){
            if(root->left==NULL) {
                // TreeNode* temp = new TreeNode(val);
                root->left = new TreeNode(val);
                return ;
            }
            else{
                helper(root->left,val);
            }
        }
        else{
            if(root->right == nullptr){
                // TreeNode* temp = new TreeNode(val);
                root->right = new TreeNode(val);
                return ;
            }
            else{
                helper(root->right,val);
            }

        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root,val);
        return root;
    }
};