#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void f(int ind,vector<vector<int>>&ans,vector<int>&A,vector<int>&nums,int k,int n,int size)
{
    if (n==0 && size==k)
    {
        ans.push_back(A);
        return;
    }
    for (int i=ind;i<nums.size();i++)
    {
        if (nums[i]>n) {break;}
        A.push_back(nums[i]);
        size++;
        f(i+1,ans,A,nums,k,n-nums[i],size);
        A.pop_back();
        size--;
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>A;
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        int size=0;
        f(0,ans,A,nums,k,n,size);
        return ans;
    }
};