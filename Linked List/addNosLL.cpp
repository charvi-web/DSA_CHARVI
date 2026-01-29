#include<bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};


class Solution {
public:
    ListNode* addNosInLL(ListNode* head1, ListNode* head2) {
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        ListNode* d = new ListNode(-1);
        ListNode* current = d;
        int carry =0;

        while (t1 || t2 )
        {
            int sum =0;
            sum=carry;
            if (t1)
            {
                sum+=t1->data;
            }
            if (t2)
            {
                sum+=t2->data;
            }
            ListNode* nn = new ListNode(sum%10);
            carry = sum/10;
            current->next=nn;
            current=current->next;
            if (t1) t1=t1->next;
            if (t2) t2=t2->next;
            
        }
        if (carry)
        {
            ListNode* nn = new ListNode(carry);
            current->next=nn;
            current=current->next;
        }
        return d->next;
    }
};