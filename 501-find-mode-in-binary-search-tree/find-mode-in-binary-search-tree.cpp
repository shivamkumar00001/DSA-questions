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
    void helper(TreeNode* root,vector<int> &v,int &prev ,int& maxfreq,int &curr,bool collect){
         if(root==nullptr) return;
         helper(root->left,v,prev,maxfreq,curr,collect);
         if(!first && prev == root->val){
            curr+=1;
         }
         else {
            curr =1;
         }
         prev = root->val;
         if(collect == true){
            if(curr == maxfreq){
            v.push_back(root->val);
            } 
         }
         else{
            maxfreq = max (curr,maxfreq);
         }
         first = false;
         helper(root->right,v,prev,maxfreq,curr,collect);

    }
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        int prev;
        int maxfreq = 0;
        int curr = 0;
        helper(root,v,prev,maxfreq,curr,false);
        first = true;
        curr = 0;
        helper(root,v,prev,maxfreq,curr,true);
        return v;
    }
};