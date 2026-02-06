#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(int mid,vector<int>& nums, int threshold)
{int c =0;
    for (auto it : nums)
    {
        c+=(it+mid-1)/mid;
    }
    return c<=threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans =-1;
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (f(mid,nums,threshold)==true)
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};