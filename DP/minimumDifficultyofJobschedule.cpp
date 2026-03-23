#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(vector<int>& A,int n,int idx,int d)
{
    vector<vector<int>>T(301,vector<int>(11,-1));
    

    if (d==1)
    {
        int maxD = INT_MIN;
        for (int i=idx;i<n;i++)
        {
            maxD = max(maxD,A[i]);
        }
        return maxD;
    }
if (T[idx][d]!=-1) return T[idx][d];
    int maxD = INT_MIN;
    int final = INT_MAX;
    for (int i=idx;i<=n-d;i++)
    {
        maxD = max(maxD,A[i]);
        int ans= maxD+solve(A,n,i+1,d-1);
        final=min(final,ans);
    }
    return T[idx][d]=final;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (n<d) return -1;

        return solve(jobDifficulty,n,0,d);
        
    }
};