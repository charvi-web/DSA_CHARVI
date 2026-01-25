#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarrayWithSumLessThanOrEqualToK(vector<int>& A, int k) {
        int n = A.size();
        int l=0;
        int sum=0;
        int maxlen =0;
        for (int r=0;r<n;r++)
        {
            sum+=A[r];
            while(sum>k)
            {
                sum-=A[l];
                l++;
            }

            if (sum<=k){maxlen=max(maxlen,r-l+1);}
        }
        return maxlen;
    }
};