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
        queue<TreeNode*>q;
        bool flag = true;

        q.push(root);
        while(q.size()>0){
           int s = q.size();
           while(s--){
             TreeNode* node = q.front();
             q.pop();
            
             if(node == nullptr ) {
                flag = false;
                continue;
             }
             else{
                 if(flag == false) return false;
             q.push(node->left);
             q.push(node->right); 
             }
           }
        }

        return true;
    }
};