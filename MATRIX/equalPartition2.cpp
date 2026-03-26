#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

typedef long long ll;
ll total=0;
bool horizontalcheck(vector<vector<int>>& A)
{
    int m = A.size();
    int n = A[0].size();
    unordered_set<ll>s;
    ll upper=0;
    for (int i=0;i<m-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            s.insert(A[i][j]);
            upper +=A[i][j];
        }
            ll bottom = total-upper;
            ll diff = upper-bottom;
            if (diff==0) return true;
            if (diff==(ll)A[0][0] ) return true;
            if (diff==(ll)A[0][n-1] ) return true;
            if (diff == (ll)A[i][0]) return true;
            if (i>0 && n>1 && s.count(diff))  return true;
    }
return false;
}
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                total+=grid[i][j];
            }
        }

        if (horizontalcheck(grid)) return true;
        reverse(begin(grid),end(grid));
        if (horizontalcheck(grid)) return true;
        reverse(begin(grid),end(grid));


        vector<vector<int>>transposeGrid(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                transposeGrid[j][i]=grid[i][j];
            }
        }
 
        if (horizontalcheck(transposeGrid)) return true;
        reverse(begin(transposeGrid),end(transposeGrid));
        if (horizontalcheck(transposeGrid)) return true;
        return false;
    }
};