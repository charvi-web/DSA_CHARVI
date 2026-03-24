#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP=INT_MIN;
        int n = nums.size();
        vector<int>P(n,0);
        long long prefix = 1;
        for(int i=0;i<n;i++)
        {
            prefix=prefix*nums[i];
            P[i]=prefix;
        }

        for (int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int a;
                if (i==0) a=P[j];
                else if (P[i]!=0) a = P[j]/P[i-1];
                else continue;
            maxP = max(maxP,a);
            }
        }
        return maxP;

    }
};