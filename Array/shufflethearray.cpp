#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int>ans(nums.size());
        int ind=0;
        for (int i=0;i<n;i++)
        {
            
            ans[ind]=nums[i];
            ans[ind+1]=nums[i+n];
            ind+=2;
        }
        return ans;
    }
};