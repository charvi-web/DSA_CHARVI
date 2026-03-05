#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
// stack<pair<int,int>>st;
stack<long long>st;
long long mini;
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        // if (st.empty()) st.push({val,val});
        // else st.push({val,min(val,st.top().second)});
        if (st.empty())
        {

            mini=val;
            st.push(val);
        }
        else 
        {
            if (val<mini)
            {
                st.push(2LL*val-mini);
                mini=val;
            }
            else st.push(val);
        }

    }
    
    void pop() {
        // st.pop();
        if (st.empty()) return;
        else
        {
            long long x=st.top();
            st.pop();
            if (x<mini)
            {
                mini = 2LL*mini-x;
            }
        }
    }
    
    int top() {
        // return st.top().first;
        if (st.empty()) return -1;
        long long x=st.top();
        if (mini<x) return x;
        else return mini;
    }
    
    int getMin() {
        // return st.top().second;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */