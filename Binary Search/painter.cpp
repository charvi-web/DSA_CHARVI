#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(long long mid, vector<int>& nums, int k,int B)
{
    int scount = 1;
    long long summ = 0;
    for (auto it : nums)
    {
        if (it*B+summ<=mid)
        {
            summ+=B*it;
        }
        else
        {
            scount++;
            summ=B*it;
        }
    }
    return scount<=k;
}
    int paint(int A, int B, vector<int>& C) {
        int k = A;
        vector<int>& nums=C;

        // Your code goes here
        long long ans =-1;
        long long s = (*max_element(nums.begin(),nums.end()))*B;
        long long sumOfAll=0;
        for(auto it : nums) {sumOfAll+=it;}
        int e = sumOfAll*B;
        while(s<=e)
        {
            long long mid = s+(e-s)/2;
            if (f(mid,nums,k,B))
            {
                ans=mid;
                e=mid-1;
            }
            else {s=mid+1;}
        }
        return ans;
    }
};