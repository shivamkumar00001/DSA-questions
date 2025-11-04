/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void mapParent(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);

        while(q.size()>0){
            TreeNode* top = q.front();
            q.pop();

            if(top->left){
                parent[top->left] = top;
                q.push(top->left);
            }
            if(top->right){
                parent[top->right] = top;
                q.push(top->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        mapParent(root);

        unordered_map<TreeNode* ,bool> visited;

        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int dist =0;
        while(q.size()>0){
            int x = q.size();

            if(dist == k) break;
            while(x>0){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                 if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if(parent.count(curr) && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] =true;
                }
                x--;
            }
            dist++;
        }

        vector<int>ans;

        while(q.size()>0){
            ans.push_back(q.front()->val);
            q.pop();
        } 
        return ans;
        
    }
};