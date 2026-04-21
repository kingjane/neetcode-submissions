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
    Node* cloneGraph(Node* node) {
        queue<Node*> que;
        if (node) {
            que.push(node);
        } else 
            return node;
        Node* cln = new Node(node->val);
        vector<Node*> arr(102);
        arr[node->val] = cln;
        while (!que.empty()) {
            Node* curr = que.front();
            que.pop();
            for (auto& ele : curr->neighbors) {              
                if (!arr[ele->val]) {
                    arr[ele->val] = new Node(ele->val);
                    que.push(ele);
                }
                arr[curr->val]->neighbors.push_back(arr[ele->val]);
            }
        }
        return cln;
    }
};