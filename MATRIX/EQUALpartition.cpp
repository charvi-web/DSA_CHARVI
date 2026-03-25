class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long m = grid.size();
        long long n = grid[0].size();
        long long totalSum = 0;
        vector<long long>rowSum(m,0);
        vector<long long>colSum(n,0);

        for(long long i=0;i<m;i++)
        {
            for(long long j=0;j<n;j++)
            {
                totalSum += grid[i][j];
                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
            }
        }
        if (totalSum%2!=0) return false;
        long long upper = 0;
        for(long long i=0;i<=m-2;i++)
        {
            upper += rowSum[i];
            if (upper==totalSum-upper) return true;
        }
        long long left = 0;
        for(long long j=0;j<=n-2;j++)
        {
            left += colSum[j];
            if (left==totalSum-left) return true;
        }
        return false;
    }
};