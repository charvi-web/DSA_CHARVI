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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==nullptr) {return head;}

        // int N=0;
        // ListNode* temp = head;
        // while(temp)
        // {
        //     N++;
        //     temp=temp->next;
        // }
        // int cnt=0;
        // if (n==N)
        // {
        //     ListNode* t = head;
        //     head=head->next;
        //     delete t;
        //     return head;
        // }
        // int k = N-n+1;

        // ListNode* tempo = head;
        // ListNode* prev = nullptr;

        // while (tempo)
        // {
        //     cnt++;
        //     if (cnt==k)
        //     {
        //         prev->next=prev->next->next;
        //         delete prev->next;

        //     }
        //     prev=tempo;
        //     tempo=tempo->next;
        // }
        // return head;


        ListNode* fast = head;
        ListNode* slow =head;

        for (int i=0;i<n;i++)
        {
            fast=fast->next;
        }
      
    if (fast == nullptr) {
    ListNode* del = head;
    head = head->next;
    delete del;
    return head;
}
        

        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* d = slow->next;
        slow->next=d->next;
        delete d;
        return head;
    }

};