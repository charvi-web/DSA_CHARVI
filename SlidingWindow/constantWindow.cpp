#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        int maxsum = 0;

        for (int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        int l = 0;
        int r = k-1;
        maxsum = sum;
        while (r<n-1)
        {
            sum -= nums[l];
            l++;
            r++;
            sum += nums[r];
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};