#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int color,int inicolor,int n,int m)
{
          int delrow[] = {-1,0,1,0};
          int delcol[] = {0,1,0,-1};
    ans[row][col]= color;
    for(int i=0;i<4;i++)
    {
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==inicolor)
        {
            dfs(nrow,ncol,ans,image,color,inicolor,n,m);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        if (color==inicolor) return image;

          int n = image.size();
          int m = image[0].size();
          vector<vector<int>>ans = image;
          dfs(sr,sc,ans,image,color,inicolor,n,m);
          return ans;
    }
};