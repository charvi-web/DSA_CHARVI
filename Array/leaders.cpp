#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int>ans;
      for (int i=n-1;i>=0;i--)
      {
        if (nums[i]>maxi)
        {
            ans.push_back(nums[i]);
        }
        maxi = max(maxi,nums[i]);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};