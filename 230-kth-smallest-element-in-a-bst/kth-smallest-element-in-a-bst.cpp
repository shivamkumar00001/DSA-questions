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
   int count =0;
    int kthSmallest(TreeNode* root, int k) {
       if(root == NULL) return val;
      kthSmallest(root->left,k);
      count+=1;
      if(k == count){
        val = root->val;
        return val;
      }
      kthSmallest(root->right ,k );
      return val;
    }
};