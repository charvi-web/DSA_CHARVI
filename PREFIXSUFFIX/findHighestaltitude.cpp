#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = INT_MIN;
        vector<int>prefixSum(n,0);
        prefixSum[0]= gain[0];
        if (n==1) return max(0,gain[0]);
        for (int i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1]+gain[i];
            maxi = max({prefixSum[i],0,maxi,prefixSum[0]});
        }
        return maxi;
    }
};