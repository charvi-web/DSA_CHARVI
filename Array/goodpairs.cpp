#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // unordered_map<int,int>m;
        // int cnt=0;
        // for(auto it : nums)
        // {
        //     cnt+=m[it];
        //     m[it]++;
        // }
        // return cnt;

        unordered_map<int,int>m;
        for(auto it : nums)
        {
            m[it]++;
        }
        int cnt = 0;
        for(auto it : m)
        {
            int n = it.second;
            cnt += (n*(n-1))/2;
        }
        return cnt;
    }
};