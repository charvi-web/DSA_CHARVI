#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int val){
        data=val;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertDLL (vector<int>&A)
{
    Node* head = new Node(A[0]);
    Node* prev = head;
    for (int i=1;i<A.size();i++)
    {
        Node* temp = new Node(A[i]);
        temp->back=prev;
        prev->next = temp;
        prev=temp;
    }
    return head;
}
void printDLL(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    vector<int>A={1,2,3,4,5};
    Node* head = convertDLL(A);
    printDLL(head);
    return 0;
    
}