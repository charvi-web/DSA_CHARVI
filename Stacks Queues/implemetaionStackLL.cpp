#include <bits/stdc++.h>
using namespace std;
class LinkedListStack {
struct Node{
int data;
Node* next;
Node(int val)
{
    data=val;
    next = nullptr;
}
};
Node* topNode;
int ssize;

public:
    LinkedListStack() {
        topNode = nullptr;
        ssize =0;

    }
    
    void push(int x) {
        Node* temp = new Node(x);
        temp->next=topNode;
        topNode=temp;
        ssize++;
   
    }
    
    int pop() {
        if (isEmpty()) return -1;
        int value = topNode->data;
        Node* temp = topNode;
        topNode=topNode->next;
        delete temp;
        ssize--;
        return value;
  
    }
    
    int top() {
        if (isEmpty()) return -1;
        return topNode->data;
    }
    
    bool isEmpty() {
  return ssize==0;
    }
};