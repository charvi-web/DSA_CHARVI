#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getfloor(vector<int>& nums, int x)
    {
        int s = 0;
        int e = nums.size() - 1;
        int floorVal = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] <= x)
            {
                floorVal = nums[mid];  // possible floor
                s = mid + 1;           // try for closer one
            }
            else
            {
                e = mid - 1;
            }
        }
        return floorVal;
    }

    int getceil(vector<int>& nums, int x)
    {
        int ceilVal = -1;
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] >= x)
            {
                ceilVal = nums[mid];   // possible ceil
                e = mid - 1;           // search left
            }
            else
            {
                s = mid + 1;
            }
        }
        return ceilVal;
    }

    vector<int> getFloorAndCeil(vector<int>& nums, int x)
    {
        return { getfloor(nums, x), getceil(nums, x) };
    }
};
