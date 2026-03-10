#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>nextGreater(vector<int>&A)
{
   
    stack<int>st;
    int n = A.size();
    vector<int>ans(n,n);
    for (int i =n-1;i>=0;i--)
    {
        while(!st.empty() && A[st.top()]<=A[i])
        {
            st.pop();
        }
        if (!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n,0);
        vector<int>ans=nextGreater(temperatures);
        for (int i=0;i<n;i++)
        {
            if (ans[i]==n) res[i]=0;
            else res[i]=ans[i]-i;
        }
        return res;
    }
};