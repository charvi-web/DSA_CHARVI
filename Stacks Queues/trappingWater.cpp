#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        // vector<int>prefix(n);
        // prefix[0]=height[0];
        // for (int i=1;i<n;i++)
        // {
        //     prefix[i]=max(prefix[i-1],height[i]);
        // }

        // vector<int>suffix(n);
        // suffix[n-1]=height[n-1];
        // for (int i=n-2;i>=0;i--)
        // {
        //     suffix[i]=max(suffix[i+1],height[i]);
        // }

        // for (int i=0;i<n;i++)
        // {
        //     int leftMax = prefix[i];
        //     int rightMax = suffix[i];
        //     if (height[i]<leftMax && height[i]<rightMax)
        //     total+=min(leftMax,rightMax)-height[i];
        // }
        int lmax = 0;
        int rmax = 0;
        int l=0;
        int r = n-1;
        while (l<r)
        {
            if (height[l]<=height[r])
            {
                if (lmax>height[l])
                {
                    total+=lmax-height[l];
                }
                else {lmax=height[l];}
                l++;
            }
            else
            {
                if (rmax>height[r])
                {
                    total+=rmax-height[r];
                }
                else {rmax=height[r];}
                r--;
            }
        }
        return total;
    }
};