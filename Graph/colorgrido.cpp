#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>grido=grid;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int orig=grid[row][col];
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            bool isBorder = false;
            for(int i=0;i<4;i++)
            {
                int nr = r+delrow[i];
                int nc = c+delcol[i];

                if (nr<0 || nr>=n || nc<0 || nc>=m)
                {
                    isBorder=true;
                }
                else if (grid[nr][nc]!=orig)
                {
                    isBorder=true;
                }
                else if (!vis[nr][nc])
                {
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
            if (isBorder) {grido[r][c]=color;}
        }
        return grido;
    }
};