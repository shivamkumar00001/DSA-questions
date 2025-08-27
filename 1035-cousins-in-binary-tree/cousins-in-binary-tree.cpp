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

 // dfs soln 
class Solution {
public:
   int depthx =-1;
   int depthy =-1;
   TreeNode* parentx = nullptr;
   TreeNode* parenty = nullptr;
   void helper( TreeNode* root,TreeNode* parent, int x, int y,int d){
     if(root == nullptr) return ;

     if(root->val == x){
        depthx = d;
        parentx = parent;
     }
     else if(root->val == y){
        depthy = d;
        parenty = parent;
     }
     helper(root->left,root, x,y,d+1);
     helper(root->right,root, x,y,d+1);
   }
    bool isCousins(TreeNode* root, int x, int y) {  
        helper(root ,nullptr, x,y,0);
        if(depthx == depthy ) return parentx!= parenty;
        return false;
    }
};