#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int N = 2*n;
        vector<int>ans(N);
        for (int i=0;i<N;i++)
        {
            ans[i]=nums[(i+n)%n];
        }
        return ans;
    }
};