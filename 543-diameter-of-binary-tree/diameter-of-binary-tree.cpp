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
// class Solution {
// public:
//     int maxDia =0;
//     int maxh(TreeNode *root){
//         if(!root) return 0;
//         return max(1+maxh(root->left), 1+maxh(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         int left =0;
//         int right =0;
//         if(!root) return 0;
//         int dia = maxh(root->left)+maxh(root->right);
//         return max({dia,diameterOfBinaryTree(root->left),
//         diameterOfBinaryTree(root->right)});
        
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
    
    int maxdia =0;

    int height(TreeNode * root){
        if (!root) return 0;
        
        int left = height(root->left);
        int right = height(root->right);

        maxdia = max(maxdia, left+right);

        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);
        return maxdia;
    }
};