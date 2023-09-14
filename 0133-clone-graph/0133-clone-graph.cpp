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
    unordered_map<Node*,Node*>copies;
    Node* cloneGraph(Node* node) {
      if(!node) return NULL;
       Node* copy = new Node(node->val,{});
       copies[node] = copy;
        queue<Node*>q;
        q.push(node);
        
        while(!q.empty()){
            Node* curr= q.front();
            q.pop();
            for(auto it:curr->neighbors){
                if(copies.find(it)==copies.end()){
                    copies[it] = new Node(it->val,{});
                    q.push(it);
                }
                
                copies[curr]->neighbors.push_back(copies[it]);
            }
        }
        return copy;
    }
};