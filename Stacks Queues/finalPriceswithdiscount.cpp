#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>res(n);
        for (int i=0;i<n;i++) res[i]=0;
        for (int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>prices[i])
            {
                st.pop();
            }
            if (!st.empty()) res[i]=st.top();
            st.push(prices[i]);
        }
        vector<int>ans(n);
        for (int i=0;i<n;i++)
        {
            ans[i]=prices[i]-res[i];
        }
        return ans;
    }
};