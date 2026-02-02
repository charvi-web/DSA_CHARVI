#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Minisearch(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int ans = INT_MAX;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (nums[mid]>=nums[s])
            {
                ans = min(ans,nums[s]);
                s=mid+1;
            }
            else 
            {
                ans = min(ans,nums[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};