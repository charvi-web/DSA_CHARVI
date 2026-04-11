#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k=k%n;
vector<vector<int>>original=mat;
        for(int a = 0;a<k;a++)
        {
            for (int i=0;i<m;i++)
        {
            
                if (i%2==0)
            {
                for (int j=0;j<n-1;j++)
                {
                    swap(mat[i][j],mat[i][j+1]);
                }
            }
            else
            {
                for (int j=n-1;j>0;j--)
                {
                    swap(mat[i][j],mat[i][j-1]);
                }
            }
        }
        }
        if (mat==original) return true;
        return false;
    }
};