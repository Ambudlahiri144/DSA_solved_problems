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
    Node* cloneFunc(Node* node,unordered_map<Node*,Node*>& mp){
        if(!node) return NULL;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto neighbour:node->neighbors){
            if(mp.find(neighbour) == mp.end()){
                (newNode->neighbors).push_back(cloneFunc(neighbour,mp));

            }else{
                (newNode->neighbors).push_back(mp[neighbour]);
            }
        }

        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        return cloneFunc(node,mp);
        
    }
};