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
   int val ;
   void helper( TreeNode* root,int k , int& count){
      if(root == NULL) return;
      helper(root->left,k,count);
      count+=1;
      if(k == count){
        val = root->val;
        return ;
      }
      helper(root->right ,k ,count);
   }
    int kthSmallest(TreeNode* root, int k) {
       int count =0;
       helper(root,k,count);
       return val;
    }
};