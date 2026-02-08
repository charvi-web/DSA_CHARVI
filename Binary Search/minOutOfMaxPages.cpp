#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(int mid,vector<int> &nums, int m)
{
    int scount = 1;
    int pages = 0;
    for (auto it : nums)
    {
        if (it+pages<=mid)
        {
            pages+=it;
        }
        else
        {
            scount++;
            pages=it;
        }
    }
    return scount<=m;
}
    int findPages(vector<int> &nums, int m)  {
        int ans =-1;
        if (m>nums.size()) return ans;
        int s = *max_element(nums.begin(),nums.end());
        int sumOfAll = 0;
        for (auto it : nums) {sumOfAll+=it;}
        int e = sumOfAll;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (f(mid,nums,m)) 
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};