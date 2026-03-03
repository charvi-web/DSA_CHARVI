#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int priority(char c)
{
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    else return -1;
}
string postfix(string s){
string ans ="";
        stack<char>st;
        for (int i=0;i<s.size();i++)
        {
            if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                ans.push_back(s[i]);
            }

            else if (s[i]=='(') {st.push(s[i]);}
            else if (s[i]==')') {while(!st.empty() && st.top()!='(')
            {
                ans.push_back(st.top());
                st.pop();
            }st.pop();
            }

            else 
            {
                while(!st.empty() && (priority(st.top())>priority(s[i]) || (priority(s[i])==priority(st.top()) && s[i]!='^')))
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
}
    string infixToPrefix(string& s) {
        // Your code goes here
        //reverse
        reverse(s.begin(),s.end());
        //swap brackets
        for (int i=0;i<s.length();i++)
        {
            if (s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
        }
        //postfix with some modification
        s=postfix(s);
        reverse(s.begin(),s.end());
        return s;
    }
};