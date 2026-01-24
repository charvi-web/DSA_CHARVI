#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sum = (n*(n+1))/2;
        // int s2 = 0;
        // for (int i=0;i<n;i++)
        // {
        //     s2+=nums[i];
        // }
        // return sum-s2;
        int XOR1= 0;
        for (int i=1;i<=nums.size();i++)
        {
            XOR1 = XOR1^i;
        }
        int XOR2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            XOR2 = XOR2^nums[i];
        }
        return XOR1^XOR2;
    }
};