#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int funcMini(vector<int>&A)
{
    if (A.size()<=1) return 0;
    int mini = INT_MAX;
    for (int i=1;i<A.size();i++)
    {
        mini = min(mini,abs(A[i]-A[i-1]));
    } 
    return mini;   
}
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>res(n - k + 1,vector<int>(m - k + 1,0));
        for(int i=0;i<=n-k;i++)
        {
            for(int j=0;j<=m-k;j++)
            {vector<int>ans;
                for (int s=i;s<i+k;s++)
                {
                    for(int e=j;e<j+k;e++)
                    {
                        ans.push_back(grid[s][e]);
                    }
                }
                sort(ans.begin(),ans.end());
                ans.erase(unique(ans.begin(),ans.end()),ans.end());
                res[i][j]=funcMini(ans);
            }
            
        }
        return res;
    }
};