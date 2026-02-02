#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 
class Solution {
public:
ListNode* reverseLL (ListNode* a)
{
    ListNode* temp = a;
    ListNode* prev = nullptr;
    while(temp)
    {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)   
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newHead=slow->next;
        newHead= reverseLL(newHead);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second)
        {
            if(first->val==second->val)
            {
                first=first->next;
                second=second->next;
            }
            else if (first->val!=second->val) return false;
            
        }
        newHead = reverseLL(newHead);
        return true;
    }
};