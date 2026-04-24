#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void f(vector<vector<int>>&ans,vector<int>&nums,vector<int>&A,vector<int>&freq)
{
    if (nums.size()==A.size())
    {
        ans.push_back(A);
        return;
    }

    for(int i=0;i<nums.size();i++)
    {
        if (!freq[i])
        {
            if (i>0 && !freq[i-1]  && nums[i]==nums[i-1])  continue;
            
                A.push_back(nums[i]);
                freq[i]=1;
                f(ans,nums,A,freq);
                A.pop_back();
                freq[i]=0;
        }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>A;
        vector<int>freq(nums.size(),0);
        sort(nums.begin(),nums.end());
        f(ans,nums,A,freq);
        return ans;
    }
};