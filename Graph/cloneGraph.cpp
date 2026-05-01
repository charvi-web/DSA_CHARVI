#include<bits/stdc++.h>
using namespace std;
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
        if (node==nullptr) return nullptr;
        queue<Node*>q;
        unordered_map<Node*,Node*>m;
        m[node]=new Node(node->val);
        q.push(node);
        while(!q.empty())
        {
            Node* n = q.front();
            q.pop();
            for (auto it : n->neighbors)
            {
                if (m.find(it)==m.end())
                {
                    q.push(it);
                    m[it]= new Node(it->val);
                }
                m[n]->neighbors.push_back(m[it]);
            }
            
        }
        return m[node];
    }
};