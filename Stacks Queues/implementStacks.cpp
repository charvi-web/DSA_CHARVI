//implementation of stacks using arrays
#include <bits/stdc++.h>
using namespace std;
class ArrayStack {
    int st[1000];
    int topp;
public:
    ArrayStack() {
        topp=-1;
    }
    
    void push(int x) {
        if (topp==999){
            cout<<"overflow";
            return;
        }
   topp++;
   st[topp]=x;
    }
    
    int pop() {
        if (topp==-1){return -1;}
        return st[topp--];
  
    }
    
    int top() {
        if (topp==-1) {cout<<"isEmpty";
        return -1;}
        return st[topp];
    
    }
    
    bool isEmpty() {
        if (topp==-1) {return true;}
        else return false;
        //return top==-1;
    }
};