#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ind = 0;
        int max_cnt = 0;
        for (int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<m;j++)
            {
                cnt+=mat[i][j];
            }
            if(cnt>max_cnt)
            {
                max_cnt=cnt;
                ind = i; 
            }
        }
        return {ind,max_cnt};
    }
};