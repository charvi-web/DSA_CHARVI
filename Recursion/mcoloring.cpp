#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool isSafe(int node,vector<vector<int>>&edges,vector<int>&colors,int color)
  {
      for (auto it : edges)
      {
          int u = it[0];
          int v = it[1];
          if (u==node && colors[v]==color) return false;
          if (v==node && colors[u]==color) return false;
      }
      return true;
  }
  bool solve(int node,int v,int m,vector<vector<int>> &edges,vector<int>&colors)
  {
      if (node==v) return true;
      for (int i=1;i<=m;i++)
      {
          if (isSafe(node,edges,colors,i))
          {
              colors[node]=i;
              if (solve(node+1,v,m,edges,colors)) return true;
              colors[node]=0;
          }
      }
      return false;
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int>colors(v,0);
        return solve(0,v,m,edges,colors);
    }
};