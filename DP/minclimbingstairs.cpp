#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0;
        int prev1 = 0;
        for (int i = 2; i <= n; i++) {
            int left = prev1 + cost[i - 1];
            int right = INT_MAX;
            if (i>1) right = prev2+cost[i-2];
        int curr = min(left, right);
        prev2=prev1;
        prev1=curr;
        }
        return prev1;
    }
};