#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int func(vector<int>& nums, int k)
{
    int l = 0;
    int cnt = 0;
    int n =  nums.size();
    map<int,int>mpp;
    for (int r=0; r<n; r++)
    {
        mpp[nums[r]]++;
        while (mpp.size()>k)
        {
            mpp[nums[l]]--;
            if (mpp[nums[l]]==0) mpp.erase(nums[l]);
            l=l+1;
        }
        cnt+=r-l+1;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};