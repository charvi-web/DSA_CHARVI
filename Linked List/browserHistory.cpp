#include <bits/stdc++.h>
using namespace std;
class Node{
public:
string data;
Node* back;
Node* next;
Node(string url)
{
    data=url;
    next=nullptr;
    back=nullptr;

}
};
class BrowserHistory {
    
public:
Node* currentPage;
BrowserHistory(string homepage)
   {
        currentPage = new Node(homepage);
   }
    
    void visit(string url) {
        Node* n  = new Node(url);
        currentPage->next = n;
        n->back = currentPage;
        currentPage=n;
    }
    
    string back(int steps) {
        while(steps && currentPage->back)
        {
            currentPage=currentPage->back;
            steps--;
        }
return currentPage->data;
    }
    
    string forward(int steps) {
        while (steps && currentPage->next)
        {
            currentPage=currentPage->next;
            steps--;
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */