#include<bits/stdc++.h>
using namespace std;
//Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
int length(ListNode* fast,ListNode*slow)
{int cnt=1;
fast=fast->next;
    while(fast!=slow)
    {
        cnt++;
        fast=fast->next;
    }
    return cnt;
}
    int findLengthOfLoop(ListNode *head) {
        if (head==NULL) return 0;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow) {return length(fast,slow);}
        }
return 0;
    }
};