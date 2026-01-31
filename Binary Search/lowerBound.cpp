#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int ans = n;
        while (s<=e)
        {
            int mid  = s+(e-s)/2;
            if (nums[mid]>=x) {ans=mid;
            e=mid-1;}
            else {s=mid+1;}
        }
        return ans;
    }
};