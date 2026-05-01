#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// int f(int i,vector<int>&nums)
// {
//     if (i==0) return nums[0];
//     if (i<0) return 0;
//     int pick = nums[i]+f(i-2,nums);
//     int notPick = f(i-1,nums);
//     return max(pick,notPick);
// }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return f(n-1,nums);
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i=1;i<n;i++)
        {
            
            int pick = nums[i]+ prev2;
            int notPick =prev1;
            int curr = max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};