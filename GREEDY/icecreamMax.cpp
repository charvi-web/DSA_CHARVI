#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt =0;
        int n = costs.size();
        sort(costs.begin(),costs.end());
        for (int x : costs)
        {
            if (x<=coins)
            {
                coins-=x;
                cnt++;
            }
            if (coins==0) return cnt;
        }
        return cnt;
    }
};