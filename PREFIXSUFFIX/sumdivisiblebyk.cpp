#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt= 0;
        int prefixSum = 0;
        unordered_map<int,int>m;
        m[0]=1;
        for (int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            int rem = prefixSum % k;
            if (rem<0) rem+=k;
            cnt+=m[rem];
            m[rem]++;
        }
        return cnt ;
    }
};