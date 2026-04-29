#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int target = nums[n/2];
        int result=0;
        for (auto it : nums)
        {
            if (target%1!=it%1) return -1;
            result+=abs(target-it)/1;
        }
        return result;
    }
};