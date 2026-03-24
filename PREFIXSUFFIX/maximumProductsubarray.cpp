#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP=INT_MIN;
        // int n = nums.size();
        // vector<long long>P(n,0);
        // long long prefix = 1;
        // for(int i=0;i<n;i++)
        // {
        //     prefix=prefix*nums[i];
        //     P[i]=prefix;
        // }

        // for (int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         long long a;
        //         if (i==0) a=P[j];
        //         else if (P[i-1]!=0) a = P[j]/P[i-1];
        //         else continue;
        //     maxP = max(maxP,(int)a);
        //     }
        // }

// upper one fails for zero

        int n = nums.size();
        long long prefix = 1;
        long long suffix = 1;
        for (int i=0;i<n;i++)
        {
            if (prefix==0) prefix=1;
            if(suffix ==0) suffix=1;
            prefix = prefix*nums[i];
            suffix = suffix*nums[n-i-1];
            maxP= max(maxP,(int)max(suffix,prefix));
        }
        return maxP;


    }
};