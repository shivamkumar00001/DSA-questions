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
    vector<int> rightSideView(TreeNode* root) {
       
       queue<TreeNode*> q;
       if(!root) return {};
       q.push(root);
       vector<int> v;

       while(q.size()>0){
        int x = q.size();
        bool flag =true;
        while(x>0){
            TreeNode* n = q.front();
            q.pop();
            if(flag){
                v.push_back(n->val);
                flag =false;
            }
            if(n->right) q.push(n->right);
            if(n->left) q.push(n->left);
            x--;
        }
        flag =true;
       }
       return v;
    }
};