#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void func(int ind,vector<vector<int>>&ans,vector<int>&nums)
{
    if (ind==nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[i],nums[ind]);
        f(ind+1,ans,nums);
        swap(nums[i],nums[ind]);
    }
}
void f(vector<vector<int>>&ans,vector<int>&A,vector<int>&nums,vector<int>&freq)
{
    if (nums.size()== A.size())
    {
        ans.push_back(A);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if (!freq[i])
        {
            A.push_back(nums[i]);
            freq[i]=1;
            f(ans,A,nums,freq);
            A.pop_back();
            freq[i]=0;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>A;
        int n = nums.size();
        vector<int>freq(n,0);
        for (int i=0;i<n;i++) freq[i]=0;
        f(ans,A,nums,freq);
        return ans;

        // vector<vector<int>>ans;
        // func(0,ans,nums);
        // return ans;

    }
};