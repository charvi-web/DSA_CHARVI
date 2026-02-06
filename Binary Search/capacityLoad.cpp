#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(int mid,vector<int>& weights, int days)
{
    int k=1;
    int load=0;
    for (auto it : weights)
    {
        if (it+load>mid)
        {
            k++;
            load=0;
        }
        load=load+it;
    }
    return k<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int s = *max_element(weights.begin(),weights.end());
        int sum = 0;
        for (auto it : weights){sum+=it;}
        int e = sum;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (f(mid,weights,days))
            {
                ans=mid;
                e=mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};