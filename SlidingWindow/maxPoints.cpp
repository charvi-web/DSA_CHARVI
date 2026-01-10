#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int n = cardPoints.size();
        int rsum = 0;
        int osum = 0;  //overall sum
        for (int i=0;i<k;i++)
        {
            lsum += cardPoints[i];
        }
        osum = lsum;
        int rind = n-1;
        for (int i = k-1;i>=0;i--)
        {
            lsum -= cardPoints[i];
            rsum += cardPoints[rind];
            rind--;
            osum = max(osum,lsum+rsum);
        }
    return osum;
    }
};