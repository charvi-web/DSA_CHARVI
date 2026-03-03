#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string postToInfix(string postExp) {

        stack<string> st;

        for (int i = 0; i < postExp.size(); i++)
        {
            if (isalnum(postExp[i]))
            {
                st.push(string(1, postExp[i]));
            }
            else
            {
                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                string con = "(" + t2 + string(1, postExp[i]) + t1 + ")";
                st.push(con);
            }
        }

        return st.top();
    }
};