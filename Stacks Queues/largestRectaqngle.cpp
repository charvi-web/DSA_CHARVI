#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>previousSmaller(vector<int>A)
{
    int n = A.size();
    stack<int>st;
    vector<int>ans(n,-1);
    for (int i=0;i<n;i++)
    {
        while (!st.empty() && A[st.top()]>=A[i])  st.pop();
        if (!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int>nextSmaller(vector<int>A)
{

    int n = A.size();
    stack<int>st;
    vector<int>ans(n,n);
    for (int i=n-1;i>=0;i--)
    {
        while (!st.empty() && A[st.top()]>=A[i])  st.pop();
        if (!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>L = previousSmaller(heights);
        vector<int>R = nextSmaller(heights);
        int area = 0;
        for (int i=0;i<n;i++)
        {
            int leftMax = L[i];
            int rightMax = R[i];
            int width = rightMax-leftMax-1;
            int height = heights[i];
            area = max(area,height*width);
        }
        return area;
    }
};