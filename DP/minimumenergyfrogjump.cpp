#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int frogJump(int n, vector<int> &heights) {
        // vector<int>dp(n,0);
        // dp[0]=0;
        int prev2=0;
        int prev1=0;
        for (int i=1;i<n;i++)
        {
            // int left = dp[i-1]+ abs(heights[i]-heights[i-1]);
            // int right= INT_MAX;
            // if (i>1)
            // right = dp[i-2]+abs(heights[i]-heights[i-2]);
            // dp[i-1]= min(left,right);
            int left = prev1+abs(heights[i]-heights[i-1]);
            int right = INT_MAX;
            right = prev2+abs(heights[i]-heights[i-2]);
            int curr = min(left,right);
            prev2=prev1;
            prev1=curr;

        }
                // return dp[n-1];
                return prev1;
    }
};