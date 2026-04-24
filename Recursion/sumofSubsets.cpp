#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void f(int ind,vector<int>&A,vector<int>&nums,int sum)
  {
    if (ind==nums.size())
    {
        A.push_back(sum);
        return;
    }
    f(ind+1,A,nums,sum+nums[ind]);
    f(ind+1,A,nums,sum);

  }
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        int sum=0;
        vector<int>A;
        f(0,A,nums,sum);
        sort(A.begin(),A.end());
        return A;
    }
};