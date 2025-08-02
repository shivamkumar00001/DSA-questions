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
    
    bool isCompleteTree(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);

       bool found_null = false;

       while(q.size()>0){
           TreeNode* curr = q.front();
           q.pop();

           if(curr == NULL){
             found_null = true;
           }
           else{
            if(found_null) return false;
            q.push(curr->left);
            q.push(curr->right);
           }
       }

       return true;

    }
};











