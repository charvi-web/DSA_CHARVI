#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int upperBound(vector<int>&nums,int x)
{
    int s = 0;
        int n = nums.size();
        int e = n-1;
        int ans = n;
        while (s<=e)
        {
            int mid  = s+(e-s)/2;
            if (nums[mid]>x) {ans=mid;
            e=mid-1;}
            else {s=mid+1;}
        }
        return ans;

}
bool f(int mid,vector<vector<int>>& matrix, int k)
{int cnt=0;
    for (int i=0;i<matrix.size();i++)
    {
        cnt+=upperBound(matrix[i],mid);
    }
    return cnt>=k;

}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = matrix[0][0];
        int e = matrix[n-1][m-1];
        int ans=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if (f(mid,matrix,k))
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};