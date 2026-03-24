#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>P(n,0);
        long long suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            P[i] = suffix;
            suffix = suffix * nums[i];
        }

        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            P[i] = P[i] * prefix;
            prefix = prefix * nums[i];
        }
        return P;
    }
};