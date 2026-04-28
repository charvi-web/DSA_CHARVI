#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(long long mid,vector<int>& candies, long long k)
{
long long cnt=0;
        for(auto it : candies)
    {
        cnt+=it/mid;
    }
    return cnt>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        long long s = 1;
        long long e = *max_element(candies.begin(),candies.end());
        long long ans =0;
        while (s<=e)
        {
            long long mid = s+(e-s)/2;
            if (f(mid,candies,k))
            {
                ans = mid;
                s=mid+1;   
            }
            else e=mid-1;
        }
        return (int)ans;
    }
};