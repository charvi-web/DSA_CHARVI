#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int max_element(vector<vector<int>>&A,int n,int m,int mid)
{
    int maxi = -1;
    int ind=-1;
    for(int i=0;i<n;i++)
    {
        if (A[i][mid]>maxi)
        {
            maxi=A[i][mid];
            ind = i;
        }
    }
    return ind;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m-1;
        while (s<=e)
        {
            int mid = (s+e)/2;
            int row = max_element(mat,n,m,mid);
            int left = (mid-1>=0)? mat[row][mid-1] : -1;
            int right = (mid+1<m)? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if (mat[row][mid]<left) {e=mid-1;}
            else s=mid+1;
        }
        return {-1,-1};
    }
};