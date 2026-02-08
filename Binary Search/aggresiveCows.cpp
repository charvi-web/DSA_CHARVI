#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(int mid,vector<int> &nums, int k)
{
    int last = nums[0];
    int cc = 1;
    for (int i=1;i<nums.size();i++)
    {
        if (nums[i]-last>=mid)
        {
            cc++;
            last=nums[i];
        }
    }
    return cc>=k;
}
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        int ans = 0;
        int s = 1;
        int e = *max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        while (s<=e)
        {
            int mid = s+(e-s)/2;
            if (f(mid,nums,k)) {ans=mid;
            s=mid+1;}
            else {e=mid-1;}
        }
        return ans;
    }
};