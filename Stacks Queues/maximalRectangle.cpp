#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

vector<int>previousSmaller(vector<int>&A)
{
    stack<int>st;
    vector<int>ans(A.size(),-1);
    for (int i=0;i<A.size();i++)
    {
        while (!st.empty() && A[st.top()]>=A[i]) st.pop();
        if (!st.empty()) ans[i]=st.top();
        st.push(i); 
    }
    return ans;
}

vector<int>nextSmaller(vector<int>&A)
{
    stack<int>st;
    vector<int>ans(A.size(),A.size());
    for (int i=A.size()-1;i>=0;i--)
    {
        while (!st.empty() && A[st.top()]>=A[i]) st.pop();
        if (!st.empty()) ans[i]=st.top();
        st.push(i); 
    }
    return ans;
}

int largestRect(vector<int>&A)
{
    long long area =0;
    vector<int>L=previousSmaller(A);
    vector<int>R=nextSmaller(A);
    for (int i=0;i<A.size();i++)
    {
        int right = R[i];
        int left = L[i];
        int width = right-left-1;
        int height = A[i];
        area = max(area,(long long)width*height);
    }
    return area;

}
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>prefixSum(n,vector<int>(m,0));

        for (int j=0;j<m;j++)
        {
            int sum=0;
            for (int i=0;i<n;i++)
            {
                if (matrix[i][j]=='1') sum+=1;
                else sum=0; 
                prefixSum[i][j]=sum;
            }

        }
        int maxi=0;
        for (int i=0;i<n;i++)
        {
            maxi=max(maxi,largestRect(prefixSum[i]));
        }
        return maxi;
    }
};