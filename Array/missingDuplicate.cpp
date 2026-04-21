#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>m;
        int missing=-1;
        int duplicate=-1;
        for (int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for (int i=1;i<=nums.size();i++)
        {
            if (m[i]==2)
            {
                duplicate=i;
            }
            if (m[i]==0)
            {
                missing=i;
            }

        }
        return {duplicate,missing};
    }
};