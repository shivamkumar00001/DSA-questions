/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void helper(TreeNode* root,string & s){
        if(root == NULL) return;
        s += to_string(root->val) + ",";
        helper(root->left,s);
        helper(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        helper(root,s);
        // if(!s.empty()) s.pop_back();
        return s;
    }
    

    TreeNode*  helper1(vector<int>& vals,int & idx,int bound){
        if(idx>=vals.size() || vals[idx]>bound) return nullptr;
        int val = vals[idx++];
        TreeNode* root = new TreeNode(val);

        root->left= helper1(vals,idx,val);
        root->right = helper1(vals,idx,bound);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> vals;
        // stringstream ss(data);
        // string token;
        // while (getline(ss, token, ',')) {
        //     vals.push_back(stoi(token));
        // }
        for(int i=0;i<data.size();i++){
         string s="";
            while(data[i]!=','){
                s+=data[i];
                i++;
            }
            vals.push_back(stoi(s));
        }

        int idx = 0;
        return helper1(vals , idx , INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;