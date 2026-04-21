#include<bits/stdc++.h>
using namespace std;
int countSubsequences(int ind,vector<int>&nums, int k,int summ)
{
    if(ind==nums.size())
    {
        if (summ==k)
        {return 1;}
        return 0;
    }
    
    
   
    summ+=nums[ind];
    int l = countSubsequences(ind+1,nums,k,summ);
    
    summ-=nums[ind];
    int r = countSubsequences(ind+1,nums,k,summ);
    return l+r;
}



int countSubsequences(vector<int>& nums, int k) {
    // write your code here 
    int summ=0;
    return countSubsequences(0,nums,k,summ);
    
    
}