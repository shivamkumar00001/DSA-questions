/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    vector<Node*>registered;

    void dfs(Node* node , Node* clone){

        for(auto neighbor: node->neighbors){
            if(not registered[neighbor->val]){
                Node* temp = new Node(neighbor->val);
                registered[temp->val] = temp;
                clone->neighbors.push_back(temp);
                dfs(neighbor, temp);
            }
            else {
                
                clone->neighbors.push_back(registered[neighbor->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* clone = new Node(node->val);
        registered.resize(111);
        registered[clone->val] = clone ;

        dfs(node ,clone);
        return clone ;
    }
};