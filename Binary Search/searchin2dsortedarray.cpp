#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // for(int i=0;i<n;i++)
        // {
        //     if (target>=matrix[i][0] && target<=matrix[i][m-1])
        //     {
        //         return f(matrix[i],target); f mei BS
        //     }
        // }
        // return false;
        int s =0;
        int e = n*m-1;
        while (s<=e)
        {
            int mid = (s+e)/2;
            int row = mid/m;
            int col =mid%m;
            if (matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]>target)
            {
                e=mid-1;
            }
            else s=mid+1;

        }
        return false;
    }
};