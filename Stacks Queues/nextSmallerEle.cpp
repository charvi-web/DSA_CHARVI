#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextSmallerElements(vector<int>& arr) {
        // Your code goes here
        stack<int>st;
        int n = arr.size();
        vector<int>res(n,-1);
        for (int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>=arr[i])
            {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();
            st.push(arr[i]);
        }
    return res;
    }
};
