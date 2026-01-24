#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();
        int maxlen = 0;
        map<long long,int>m;
        long long sum = 0;
        for (int i=0;i<n;i++)
        {
            sum+=nums[i];
            if (sum==k)
            {
                maxlen = max(maxlen,i+1);
            }
            long long rem = sum-k;
            if (m.find(rem)!=m.end())
            {
                maxlen = max(maxlen,i-m[rem]);
            }
            if (m.find(sum) == m.end()) 
            {
                m[sum] = i;
            }
        }
        return maxlen;
    }
};
