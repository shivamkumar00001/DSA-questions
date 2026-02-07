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
    int hx=-1;
    int hy=-1;
    TreeNode* parentx;
    TreeNode* parenty;
    void helper(TreeNode* root,int x,int y, TreeNode* parent,int count){

        if(root == nullptr) return ;
        if(root->val == x){
            parentx = parent;
            hx = count;
            return;
        }
        if(root->val == y){
            parenty = parent;
            hy = count;
            return;
        }

        helper(root->left, x, y, root, count+1);
        helper(root->right, x, y, root, count+1);

    }
    bool isCousins(TreeNode* root, int x, int y) {

        helper(root, x,y,root,0);
        if(parentx == parenty) return false;
        return hx == hy;

    }
};