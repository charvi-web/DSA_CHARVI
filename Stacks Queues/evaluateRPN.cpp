#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for (int i=0;i<tokens.size();i++)
        {
            string s = tokens[i];
            if (s=="+" || s=="-" || s=="*" || s=="/")
            {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();

                int result ;
                if (s == "+") result = t2 + t1;
                else if (s == "-") result = t2 - t1;
                else if (s == "*") result = t2 * t1;
                else result = t2 / t1;

                st.push(result);
                
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};