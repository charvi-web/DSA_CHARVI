#include<bits/stdc++.h>
using namespace std;
Solution {
public:
vector<int>previousSmaller(vector<int>&A)
{
    int n = A.size();
    vector<int> res(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && A[st.top()]>=A[i])
        {
            st.pop();
        }
        if (!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}

vector<int>nextSmaller(vector<int>&A)
{
    int n = A.size();
    vector<int>res(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && A[st.top()]>A[i])
        {
            st.pop();
        }
        if (!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}
    int sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        int mod = (int)(1e9+7);
        vector<int>ps=previousSmaller(arr);
        vector<int>ns=nextSmaller(arr);
        for (int i=0;i<arr.size();i++)
        {
            long long left = i-ps[i];
            long long right = ns[i]-i;
            total = (total+ (left*right*arr[i]*1LL)%mod)%mod;
        }
        return total;
    }

};