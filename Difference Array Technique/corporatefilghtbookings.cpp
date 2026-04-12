#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n,0);
        for (auto &it : bookings)
        {
            int l = it[0];
            int r = it[1];
            int s = it[2];
            diff[l-1]+=s;
            if (r<n) diff[r]-=s;
        }
        for (int i=1;i<n;i++) {
            diff[i]+=diff[i-1];
        }
        return  diff;
    }
};