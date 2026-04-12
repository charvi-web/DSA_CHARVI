#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool can_make_zeroes(vector<int>& nums, vector<vector<int>>& queries,
                         int k) {

        int n = nums.size();
        vector<int> diff(n, 0);
        for (int i=0;i<k;i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int shift = queries[i][2];
            diff[left] += shift;
            if (right + 1 < n)
                diff[right + 1] -= shift;
        }
        for (int i = 1; i < n; i++)
            diff[i] = diff[i] + diff[i - 1];
        for (int i = 0; i < n; i++)
            if (nums[i] > diff[i])
                return false;
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        auto lambda = [](int x) { return x == 0; };
        if (all_of(begin(nums), end(nums), lambda)) {
            return 0;
        }
        int l=1;
        int r = queries.size();
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if (can_make_zeroes(nums,queries,mid))
            {
                ans=mid;
                r=mid-1;

            }
            else l=mid+1;

            
        }
        return ans;
    }
};