#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long long func(int k,vector<int>&piles)
{
    long long  t=0;
    for (auto it : piles)
    {
        t+=(it+k-1)/k;
    }
    return t;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int n = piles.size();
        int e = *max_element(piles.begin(), piles.end());

        int k=0;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (func(mid,piles)<=h) {
            k=mid;
            e=mid-1;}
            else s=mid+1;

        }
        return k;
    }
};