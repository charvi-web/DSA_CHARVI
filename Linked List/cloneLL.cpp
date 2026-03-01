#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp= head;
        while(temp)
        {
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next=n;
            temp=temp->next->next;
        }
        temp=head;
        while(temp)
        {
            Node* c= temp->next;
            if (temp->random)
            c->random = temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy =  new Node(-1);
        Node* res = dummy;
        while(temp)
        {
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
    return dummy->next;
    }
};