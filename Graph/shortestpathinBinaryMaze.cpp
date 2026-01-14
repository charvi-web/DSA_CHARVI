#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        if (n==1) return 1;
        dist[0][0]=1;
        while(!q.empty())
        {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int d = q.front().first;
            q.pop();
            for(int delrow = -1;delrow<=1;delrow++)
            {
                for (int delcol = -1;delcol<=1;delcol++)
                {
                    int nrow = r + delrow;
                    int ncol = c + delcol;
                    if (nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && 
                    dist[nrow][ncol] > d + 1)
                    {
                        dist[nrow][ncol] = d + 1;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                        if (nrow == n-1 && ncol==n-1)
                        {
                            return dist[nrow][ncol];
                        }
                    }
                }
            }
        }
    return -1;
    }
};