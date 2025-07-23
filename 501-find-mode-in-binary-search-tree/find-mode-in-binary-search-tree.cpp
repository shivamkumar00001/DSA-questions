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
    bool first = true;
    void helper1(TreeNode* root, vector<int>&v,int &prev ,int maxfreq,int &curr){
        if(root == nullptr) return ;
        helper1(root->left,v,prev,maxfreq,curr);
        if(!first && prev == root->val){
            curr+=1;
         }
         else {
            curr =1;
         }
          if(curr == maxfreq){
                v.push_back(root->val);
            }
        prev = root->val;
         first = false;
         helper1(root->right,v,prev,maxfreq,curr);
    }
    void helper(TreeNode* root,int &prev ,int& maxfreq,int &curr){
         if(root==nullptr) return;
         helper(root->left,prev,maxfreq,curr);
         if(!first && prev == root->val){
            curr+=1;
         }
         else {
            curr =1;
         }
         prev = root->val;
         maxfreq = max (curr,maxfreq);
         first = false;
         helper(root->right,prev,maxfreq,curr);

    }
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        int prev;
        int maxfreq = 0;
        int curr = 0;
        helper(root,prev,maxfreq,curr);
        first = true;
        curr = 0;
        helper1(root,v,prev,maxfreq,curr);
        if(v.size() == 0) return {root->val};
        return v;
    }
};