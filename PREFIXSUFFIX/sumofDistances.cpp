#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        vector<ll>arr(nums.size(),0);
        unordered_map<int,ll>indexcount;
        unordered_map<int,ll>indexsum;
        for (int i=0;i<nums.size();i++)
        {
            ll count = indexcount[nums[i]];
            ll sum = indexsum[nums[i]];
            arr[i]+= count*i-sum;
            indexcount[nums[i]]+=1;
            indexsum[nums[i]]+=i;
        }
        indexcount.clear();
        indexsum.clear();
        for (int i=nums.size()-1;i>=0;i--)
        {
            ll count = indexcount[nums[i]];
            ll sum = indexsum[nums[i]];
            arr[i]+= sum-count*i;
            indexcount[nums[i]]+=1;
            indexsum[nums[i]]+=i;
        }
        return arr;
    }
};