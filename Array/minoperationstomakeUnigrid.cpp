#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(); //m*n
        int m = grid[0].size();
        vector<int>vec;
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vec.push_back(grid[i][j]);
            }
        }
        int L = vec.size();
        sort(vec.begin(),vec.end());  //llogl
        int target = vec[L/2];
        int result = 0;
        for(int &num : vec)         //l
        {
            if(num%x != target%x) return -1;
            result+= abs(target-num)/x;
        }
        return result;
    }
};