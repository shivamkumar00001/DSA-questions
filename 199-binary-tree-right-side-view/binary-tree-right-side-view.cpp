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
        
        queue<TreeNode*>q;

        q.push(root);
        vector<int>ans;
        while(q.size()>0){
            int s = q.size();
            vector<int>v;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    v.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(v.size()>0)ans.push_back(v[v.size()-1]);
        }

          return ans;
    }
};