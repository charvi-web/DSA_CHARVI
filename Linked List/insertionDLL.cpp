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
Node* insertBeforeHead(Node* &head,int val)
{
    if (head==nullptr) {return new Node(val);}
    Node* newHead = new Node(val);
    newHead->next=head;
    head->back=newHead;
    return newHead;
}
Node* insertBeforeTail(Node* &head,int val)
{
    if (head==nullptr) {return new Node(val);}
    if (head->next==nullptr) {return insertBeforeHead(head,val);}
    Node* s = new Node(val);
    Node* temp = head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    s->next=temp->next;
    temp->next=s;
    s->back=temp;
    temp->next->back=s;
    return head;
}
Node* insertBeforeK(Node* &head,int k,int val)
{
    if (head==nullptr) {
        if (k==1) {return new Node(val);}
        else return head;
    }
    int cnt =0;
    Node* temp=head;
    while(temp)
    {
        cnt++;
        if (cnt==k)
        {break;}
        temp=temp->next;
    }
    Node* previous = temp->back;
    Node* s =new Node(val);
    s->next=temp;
    previous->next=s;
    s->back=previous;
    temp->back=s;
    return head;

}
void insertBeforeNode(Node* &head,Node* &n,int val)
{
    Node* previous = n->back;
    Node* s = new Node(val);
    s->next=n;
    previous->next=s;
    s->back=previous;
    n->back=s;
    return;

}
int main(){
    vector<int>A={1,2,3,4,5};
    Node* head = convertDLL(A);
    printDLL(head);
    cout<<endl;
    head=insertBeforeHead(head,0);
    printDLL(head);
    cout<<endl;
    head = insertBeforeTail(head,6);
    printDLL(head);
    cout<<endl;
    head=insertBeforeK(head,4,10);
    printDLL(head);
    cout<<endl;
    insertBeforeNode(head,head->next->next->next->next,15);
    printDLL(head);
   
    return 0;
    
}