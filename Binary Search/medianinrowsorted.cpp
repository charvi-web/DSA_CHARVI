#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int upperBound(int x,vector<int> &A)
  {
      int ub = A.size();
      int s = 0;
      int e =  A.size()-1;
      while(s<=e)
      {
          int mid = (s+e)/2;
          if (A[mid]>x)
          {
              ub = mid;
              e=mid-1;
          }
          else s=mid+1;
      }
      return ub;
  }
  bool f(int mid,vector<vector<int>> &mat,int k)
  {int n = mat.size();
  int m = mat[0].size();
  int cnt=0;
      for(int i=0;i<n;i++)
      {
          cnt+= upperBound(mid,mat[i]);
      }
      return cnt>k;
  }
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int s = mat[0][0];
        int e = mat[0][m-1];
        int ans =0;
        for(int i=0;i<n;i++)
        {
            s = min(s,mat[i][0]);
            e = max(e,mat[i][m-1]);
        }
        int k = (n*m)/2;
        while (s<=e)
        {
            int mid = (s+e)/2;
            if (f(mid,mat,k))
            {
                ans = mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};
