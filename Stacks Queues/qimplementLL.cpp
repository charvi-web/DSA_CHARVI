#include <bits/stdc++.h>
using namespace std;
class LinkedListQueue {

    struct Node{
        int data;
        Node* next;
        Node(int val)
        {
            data=val;
            next=nullptr;
        }
    };
    Node* start;
    Node* end;
    int qsize;

public:
    LinkedListQueue() {
        start = nullptr;
        end = nullptr;
        qsize=0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        if (start==nullptr) start=end=temp;
        else {end->next=temp;
        end=temp;}
        qsize++;
   
    }
    
    int pop() 
    {
        if (start==nullptr) return -1;
        Node* temp = start;
        int v = temp->data;
        start=start->next;
        delete temp;
        qsize--;
        if (start == nullptr)
    end = nullptr;
        return v;

  
    }
    
    int peek() {
        if (start==nullptr) return -1;
    return start->data;
    }
    
    bool isEmpty() {
  return qsize==0;
    }
};