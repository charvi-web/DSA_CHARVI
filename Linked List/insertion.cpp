#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=nullptr;
    }
};
Node* convertArrToLL(vector<int>& A)
{
    Node* head = new Node(A[0]);
    Node* mover = head;
    for(int i=1;i<A.size();i++)
{
    Node* temp = new Node(A[i]);
    mover->next=temp;
    mover=temp;

}
return head;
}
void printLL(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* insertHead(Node* head,int k)
{
    Node* newHead = new Node(k);
    newHead->next=head;
    head = newHead;
    return head;
}
Node* insertTail(Node* head,int k)
{
    Node* newTail = new Node(k);
    if (head==nullptr) return newTail;
    Node* temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next = newTail;
    return head;
}
Node* insertAtK(Node* head, int k,int val)
{
    if (head==nullptr) {
        if (k==1) {return new Node(val);}
        else return head;
    }
    if (k==1)
    {
        Node* p = new Node(val);
        p->next=head;
        return p;
    }
    Node* temp = head;
    Node* s = new Node(val);
    int cnt=0;
    while(temp)
    {cnt++;
        if (cnt==k-1)
        {
            s->next = temp->next;
            temp->next=s;
            break;
        }
        temp=temp->next;
    }
    return head;
}


Node* insertAtValue(Node* head,int val)
{
    if (head==nullptr) {
        return nullptr;
    }
    if (head->data==val)
    {
        Node* p = new Node(val);
        p->next=head;
        return p;
    }
    Node* temp = head;
    Node* s = new Node(val);
    while(temp->next)
    {
        if (temp->next->data==val)
        {
            s->next = temp->next;
            temp->next=s;
            break;
        }
        temp=temp->next;
    }
    return head;
}



int main()
{
    vector<int>A={1,2,3,4,5};
    Node* head = convertArrToLL(A);
    printLL(head);
    head=insertHead(head,0);
    cout<<endl;
    printLL(head);

    head=insertTail(head,6);
    cout<<endl;
    printLL(head);

    head=insertAtK(head,4,9);
    cout<<endl;
    printLL(head);
}
