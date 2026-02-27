#include <bits/stdc++.h>
using namespace std;
//Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = nullptr;
        child = nullptr;
    }
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
        child = nullptr;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next2;
    }
};

ListNode* merge(ListNode* list1,ListNode* list2)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    while (t1 && t2)
    {
        if (t1->val < t2->val)
        {
            temp->child=t1;
            
            t1=t1->child;

        }
        else 
        {
            temp->child=t2;
           
            t2=t2->child;

        }
         temp=temp->child;
            temp->next=NULL;
    }
    if (t1) {temp->child=t1;}
    else {temp->child=t2;}
    
return dummy->child;
}
class Solution {
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        head->next = flattenLinkedList(head->next);
        head =  merge(head,head->next);
        head->next= NULL;
        return head;

    }
};