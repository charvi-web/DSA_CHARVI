#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        // for (int i=0;i<n;i++)
        // {int zeroes = 0;
        //     for (int j=0;j<n;j++)
        //     {
        //         if (nums[j]==0) zeroes++;
        //         if (zeroes<=k) {
        //             maxlen = max(maxlen,j-i+1);
        //         }
        //         else break;
        //     }
        // }
        int l=0;
       
        int zeroes=0;
        for(int r=0;r<n;r++)
        {
            if (nums[r]==0) {zeroes++;}
            if (zeroes>k)
            {
                if(nums[l]==0) zeroes--;
                l++;
            }
            if (zeroes<=k)
            {
                maxlen = max(maxlen,r-l+1);

            }

        }
        return maxlen;
    }
};