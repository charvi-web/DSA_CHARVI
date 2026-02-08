#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(int mid, vector<int>& nums, int k)
{
    int scount = 1;
    int summ = 0;
    for (auto it : nums)
    {
        if (it+summ<=mid)
        {
            summ+=it;
        }
        else
        {
            scount++;
            summ=it;
        }
    }
    return scount<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int ans =-1;
        if (nums.size()<k) return ans;
        int s = *max_element(nums.begin(),nums.end());
        int sumOfAll=0;
        for(auto it : nums) {sumOfAll+=it;}
        int e = sumOfAll;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (f(mid,nums,k))
            {
                ans=mid;
                e=mid-1;
            }
            else {s=mid+1;}
        }
        return ans;
    }
};