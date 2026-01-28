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
Node* deleteHead (Node* &head)
{
    if (head==nullptr || head->next==nullptr) return nullptr;
    Node* temp = head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
Node* deleteTail(Node* head)
{
    if (head==nullptr || head->next==nullptr) return nullptr;
    Node* temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    temp->next->back=nullptr;
    temp->next=nullptr;

    delete temp->next;
    return head;
}
Node* deleteKelement(Node* head, int k)
{
    if (head==nullptr) return head;
    int cnt = 0;
    Node* temp = head;
    while(temp)
    {
        cnt++;
        if (cnt == k) {break;}
        temp=temp->next;
    }
    Node* previous = temp->back;
    Node* front = temp->next;
    if (previous==nullptr && front==nullptr)
    {
        return nullptr;
    }
    else if (previous == nullptr)
    {
        deleteHead(head);
    }
    else if (front == nullptr)
    {
        deleteTail(head);
    }
    else
    {
        temp->back=temp->next=nullptr;
        previous->next=front;
        front->back=previous;
        delete temp;
    }
    return head;
}
void deleteNode(Node* temp)
{
    Node* previous = temp->back;
    Node* front = temp->next;
    if (front==nullptr)
    {
        temp->back=nullptr;
        previous->next=nullptr;
        delete temp;
        return;

    }
    previous->next=front;
    front->back=previous;
    temp->next=temp->back=nullptr;
    delete temp;
    return ;
}
int main(){
    vector<int>A={1,2,3,4,5};
    Node* head = convertDLL(A);
    printDLL(head);
    cout<<endl;
    deleteHead(head);
    printDLL(head);
    cout<<endl;
    head = deleteTail(head);
    printDLL(head);
    cout<<endl;
    head = deleteKelement(head, 3);
    printDLL(head);
    return 0;
    
}