#include<bits/stdc++.h>
using namespace std;
class LRUCache {
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k,int v)
        {
            key=k;
            val=v;
            prev=NULL;
            next=NULL;
        }
    };
    unordered_map<int,Node*>m;
    int capacity;
    Node* tail;
    Node* head;

     
    

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node* n)
    {
        Node* before = n->prev;
        Node* after = n->next;
        before->next=after;
        after->prev=before;
    }
    void insertAfterHead(Node* n)
    {
        Node* curr = head->next;
        
        head->next=n;
        n->next=curr;
        n->prev=head;
        curr->prev=n;
    }
   
    int get(int key) {
        if (m.find(key)==m.end()) return -1;
        Node* node = m[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (m.find(key)!=m.end())
        {
            Node* node = m[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);

        }
        else 
        {
            if (capacity==m.size()) 
            {
                Node* n = tail->prev;
                m.erase(n->key);
                deleteNode(n);
                

            }
            Node* n = new Node(key,value);
            m[key]=n;
            insertAfterHead(n);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */