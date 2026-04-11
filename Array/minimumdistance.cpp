#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        int result = INT_MAX;
        for (int k=0;k<nums.size();k++)
        {
            m[nums[k]].push_back(k);
            if (m[nums[k]].size()>=3)
            {
                vector<int>&vec = m[nums[k]];
                int siz = vec.size();
                int i = vec[siz-3];
                result = min(result,(k-i));
            }
        }
        return result == INT_MAX ? -1 : 2*(result);
    }
};