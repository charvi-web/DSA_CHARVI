#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int timesrotated(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int ans = INT_MAX;
        int i =-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (nums[mid]>=nums[s])
            {
                if (nums[s]<ans)
                {
                    i=s;
                    ans=nums[s];
                }
                s=mid+1;
            }
            else 
            {
                if (nums[mid]<ans)
                {
                    i=mid;
                    ans=nums[mid];
                }
                e=mid-1;
            }
        }
        return i;
    }
};