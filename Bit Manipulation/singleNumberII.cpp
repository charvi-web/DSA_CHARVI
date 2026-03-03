#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int,int>m;
        // for(int a : nums) {m[a]++;}
        // for (auto it : m) {if (it.second==1) return it.first;}
        
        
        // int ans=0;
        // for (int i=0;i<32;i++)
        // {
        //     int cnt =0;
        //     for (int j=0;j<nums.size();j++)
        //     {
        //         if (nums[j]&(1<<i)) cnt++;
        //         if (cnt%3==1) ans=ans|(1<<i);
        //     }

        // }
        // return ans;


        sort(nums.begin(),nums.end());
        for (int i=1;i<nums.size();i+=3)
        {
            if (nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
