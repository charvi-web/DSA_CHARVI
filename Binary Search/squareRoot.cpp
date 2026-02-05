#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int floorSqrt(int n)  {
      int s = 1;
      int ans = 0;
      int e = n;
      while(s<=e)
      {
        int mid = s+(e-s)/2;
        if ((long long)mid*mid<=n)
        {
            ans=mid;
            s=mid+1;
        }
        else {e=mid-1;}
      }
      return ans;
    }
};