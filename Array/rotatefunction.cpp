#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int F = 0;

        for (int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            F = F +  i* nums[i];
            
        }
        int maxi = F;
        for (int k=0;k<n;k++)
        {
            int newF = F + sum - n * nums[n-k-1];
            maxi = max(maxi,newF);
            F =newF;
        }
        return maxi;
    }
};