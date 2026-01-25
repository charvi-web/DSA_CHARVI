//implementing Queue using Array
#include <bits/stdc++.h>
using namespace std;
class ArrayQueue {
    int start;
    int end;
    int q[1000];
    int qsize;
    int currsize;
public:
    ArrayQueue() {
        start=-1;
        end=-1;
        currsize=0;
        qsize=1000;
    }
    
    void push(int x) {
        if (currsize==qsize) {return;}
        if (currsize==0)
        {
            start=0;
            end=0;
        }
        else{
            end=(end+1)%qsize;
            
        }
   
            q[end]=x;
            currsize++;
    }
    
    int pop() {
        if (currsize==0)
        {return -1;}
        int el = q[start];
        if (currsize==1)
        {
            end=-1;
            start=-1;
        }
        else 
        {
            start=(start+1)%qsize;
            

        }currsize--;
            return el;
  
    }
    
    int peek() {
        if (currsize==0) return -1;
        return q[start];
    
    }
    
    bool isEmpty() {
        return currsize==0;
  
    }
};