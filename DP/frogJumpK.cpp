#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int frogJump(int n, vector<int> &heights,int K) {
    vector<int>dp(n,0);

        for (int i=1;i<n;i++)
        {    int ministeps  = INT_MAX;

            for(int j=1;j<=K;j++)
            {
                if (i-j>=0)
                {
                    ministeps= min(ministeps,dp[i-j]+abs(heights[i]-heights[i-j]));
                }
            }
            dp[i]=ministeps;
        }
        return dp[n-1];
    }
};