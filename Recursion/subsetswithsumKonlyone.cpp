#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(int ind,vector<int>&A,vector<int>&nums,vector<vector<int>>&ans,int summ,int k)
{
    if (ind==nums.size())
    {
        if (summ==k)
        {ans.push_back(A);
        return true;}
        else return false;
    }
    A.push_back(nums[ind]);
    summ+=nums[ind];
    if (f(ind+1,A,nums,ans,summ,k)) return true;
    A.pop_back();
    summ-=nums[ind];
    if (f(ind+1,A,nums,ans,summ,k)) return true;
    return false;
}
    vector<vector<int>> subsets(vector<int>& nums,int k) {
        vector<vector<int>>ans;
        vector<int>A;
        f(0,A,nums,ans,0,k);
        return ans;
    }
};