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

 // this approach is giving tle ->
// class Solution {
// public:
    
//     void helper(TreeNode* root , int val,vector<vector<int>>& ans,int next,int prev){
//         if(root == nullptr){
//             ans.push_back({prev,next});
//             return;
//         }
//         if(root->val == val){
//             ans.push_back({val,val});
//             return ;
//         }
//         if(root->val>val){
//             helper(root->left,val,ans,root->val,prev);
//         }
//         else {
//          helper(root->right,val,ans,next,root->val);
//         }
//     }
//     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//         vector<vector<int>>ans;
//         for(int i=0;i<queries.size();i++){
//             helper(root,queries[i],ans,-1,-1);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& sorted) {
        if (!root) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sorted;
        inorder(root, sorted);  // O(n)
        vector<vector<int>> ans;

        for (int val : queries) {
            
            int lo = 0, hi = sorted.size() - 1;
            int floor = -1, ceil = -1;

           
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (sorted[mid] <= val) {
                    floor = sorted[mid];
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            lo = 0, hi = sorted.size() - 1;
            
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (sorted[mid] >= val) {
                    ceil = sorted[mid];
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            ans.push_back({floor, ceil});
        }

        return ans;
    }
};











