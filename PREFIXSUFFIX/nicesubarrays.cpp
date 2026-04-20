#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int func(vector<int>&nums,int goal)
{
    int l=0;
    int sum=0;
    int n = nums.size();
    int cnt =0;
    for (int r=0;r<n;r++)
{
    sum+=(nums[r]%2);
    while (sum>goal)
    {
        sum-=(nums[l]%2);
        l++;
    }
    cnt+=r-l+1;
}
return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        // return func(nums,k)-func(nums,k-1);
        int cnt = 0;
        int res=0;

        unordered_map<int,int>m;
        m[0]=1;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]%2) cnt++;
            if (m.find(cnt-k)!=m.end())
            {
                res+=m[cnt-k];
            }
            m[cnt]++;
        }
        return res;
    }
};


