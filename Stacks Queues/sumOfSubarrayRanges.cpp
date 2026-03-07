#include<bits/stdc++.h>
using namespace std;
class Solution {
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
vector<int>previousGreater(vector<int>&A)
{
    int n = A.size();
    vector<int> res(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && A[st.top()]<=A[i])
        {
            st.pop();
        }
        if (!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}

vector<int>nextGreater(vector<int>&A)
{
    int n = A.size();
    vector<int>res(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && A[st.top()]<A[i])
        {
            st.pop();
        }
        if (!st.empty()) res[i]=st.top();
        st.push(i);
    }
    return res;
}
    long long subArrayRanges(vector<int>& nums) {
        
        long long ftotal=0;
        long long stotal = 0;
       
        vector<int>ps=previousSmaller(nums);
        vector<int>ns=nextSmaller(nums);
        for (int i=0;i<nums.size();i++)
        {
            long long left = i-ps[i];
            long long right = ns[i]-i;
            stotal = stotal+ (left*right*nums[i]*1LL);
        }
        long long ltotal = 0;
        
        vector<int>pg=previousGreater(nums);
        vector<int>ng=nextGreater(nums);
        for (int i=0;i<nums.size();i++)
        {
            long long left = i-pg[i];
            long long right = ng[i]-i;
            ltotal = ltotal+ (left*right*nums[i]*1LL);
        }
        return ltotal-stotal;

        
    }
};