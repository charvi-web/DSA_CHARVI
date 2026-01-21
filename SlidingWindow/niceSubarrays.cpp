#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int func(vector<int>&nums,int goal)
{
    int l=0;
    int sum=0;
    int n = nums.size();
    int cnt =0;
    for (int r=0;r<n;r++)
{
    sum+=(nums[r]%2);
    while (sum>goal)
    {
        sum-=(nums[l]%2);
        l++;
    }
    cnt+=r-l+1;
}
return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal)-func(nums,goal-1);
    }
};