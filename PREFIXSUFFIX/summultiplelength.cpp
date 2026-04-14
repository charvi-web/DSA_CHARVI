#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int p =0;
        m[0]=-1;
        for (int i=0;i<nums.size();i++)
        {
            p+=nums[i];
            int rem = p%k;
            if (rem<0) rem+=k;
            if (m.find(rem)!=m.end()) {
                if (i-m[rem]>=2)
                return true;}
            else m[rem]=i;
        }
        return false;
    }
};