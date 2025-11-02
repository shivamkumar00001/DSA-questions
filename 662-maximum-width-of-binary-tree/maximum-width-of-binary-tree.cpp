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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , unsigned long long>> q;

        q.push({root, 0});
        unsigned long long ans =0;
        while(q.size()>0){
            int x = q.size();
            unsigned long long  first = q.front().second;
            unsigned long long  last = q.back().second;
            while(x>0){
                auto [top,i] = q.front();
                q.pop();
                if(top->left)q.push({top->left, 2*i+1});
                if(top->right)q.push({top->right, 2*i+2});
                x--;
            }
            ans = max (ans, (last-first+1));
        }
        return ans;
    }
};