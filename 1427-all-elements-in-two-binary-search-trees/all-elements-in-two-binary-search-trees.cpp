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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        vector<int> ans;
        TreeNode* node1= root1;
        TreeNode* node2= root2;

        while(st1.size()>0 || st2.size()>0 || node1 || node2){
            if(node1 || node2){
                if(node1){
                    st1.push(node1);
                    node1 = node1->left;
                }
                if(node2){
                    st2.push(node2);
                    node2 = node2->left;
                }
            }
            else{
                if(st1.empty() ||(st2.size()>0 && st2.top()->val<=st1.top()->val)){
                    ans.push_back(st2.top()->val);
                    node2= st2.top()->right;
                    st2.pop();
                }
                else if(st2.size()==0||(st1.size()>0 && st1.top()->val<=st2.top()->val)){
                    ans.push_back(st1.top()->val);
                    node1= st1.top()->right;
                    st1.pop();
                }
            }
        }

        return ans;
    }
};