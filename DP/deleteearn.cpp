#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int me = *max_element(nums.begin(),nums.end());
        vector<int>points(me+1,0);
        for (int x : nums)
        {
            points[x]+=x;
        }
        int prev2 = 0;
        int prev1 = points[0];
        for (int i=1;i<points.size();i++)
        {
            int pick = points[i]+prev2;
            int notpick = prev1;
            int curr = max(pick,notpick);
            prev2 = prev1;
            prev1=curr;
        }
        return prev1;
    }
};