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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> arr;
        if(!root) return {};
        q.push(root);
        while(q.size()>0){
            int x = q.size();
            vector<int>a;
            for(int i=0;i< x ;i++){
                TreeNode* temp = q.front();
                 if(temp)a.push_back(temp->val);
                 q.pop();
                 if(temp && temp->left)q.push(temp->left);
                 if(temp && temp->right)q.push(temp->right);

            }
            arr.push_back(a);
        }

        return arr;
    }
};