#include<bits/stdc++.h>
using namespace std;    
struct Node{
    public:
    int data;
    Node* next;
    public:
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
Node* deleteHead(Node* &head)
{
    if (head== nullptr) return nullptr;
    Node* temp = head;
    head= head->next;
    delete temp;
    return head;
}
void printLL(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* deleteTail(Node* head)
{
    if (head==nullptr || head->next==nullptr) return nullptr;
    Node* temp = head;
    while (temp->next->next)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

int main()
{
    vector<int>A={1,2,3,4,5};
    Node* head = convertArrToLL(A);
    printLL(head);
    cout<<endl;

    cout<<"After deletion of head :  "<<endl;
    deleteHead(head);
    printLL(head);

    cout<<endl;
    cout<<"After deletion of tail :  "<<endl;
    deleteTail(head);
    printLL(head);

    
}