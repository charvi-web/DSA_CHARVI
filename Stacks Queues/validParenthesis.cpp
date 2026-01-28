#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: stack<char>st;
public:
    bool isValid(string s) {
        for (int i=0;i<s.length();i++)
        {
            if (s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }

            else
            {
                if (st.empty()) return false; //opening nhi h 
                char ch = st.top();
                st.pop();
                if (s[i]==')' && ch=='(' || s[i]=='}' && ch=='{' || s[i]==']' && ch=='[')
                {
                    continue;
                }
                else
                {
                    return false;
                }

            }
        }
return st.empty();
        
    }
};