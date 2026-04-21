#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void f(int ind,vector<int>&A,vector<int>&nums,vector<vector<int>>&ans)
{
    if (ind>=nums.size())
    {
        ans.push_back(A);
        return;
    }
    A.push_back(nums[ind]);
    f(ind+1,A,nums,ans);
    A.pop_back();
    f(ind+1,A,nums,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>A;
        f(0,A,nums,ans);
        return ans;
    }
};