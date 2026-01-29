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
    ListNode* reverseDLL(ListNode* head) {
        // similar to swapping of two numbers using third variable
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* temp = head;
        ListNode* last = nullptr;
        while (temp)
        {
            last = temp->prev;
            temp->prev=temp->next;
            temp->next=last;
            temp=temp->prev;
        }
        return last->prev;
    }
};