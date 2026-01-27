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
int lengthLL (Node* head)
{
    int cnt = 0;
    Node* temp = head;
    while (temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int ifPresent(Node* head,int k)
{
    Node* temp = head;
    while(temp)
    {
        
        if (temp->data==k)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int main()
{
    vector<int>A={1,2,3,4,5};
    Node* y = new Node(A[0]);
    cout<<y<<endl;
    cout<<y->data<<endl;
    cout<<y->next<<endl;

    Node* head = convertArrToLL(A);
    cout<<head->data<<endl;
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    int l = lengthLL(head); 
    cout<<endl<<"Length of linked list is "<<l<<endl;
    cout<<"Is 3 present in linked list "<<ifPresent(head,32)<<endl;
}