#include<bits/stdc++.h>
using namespace std;
class Solution {
    
  public:
  void f(int r,int c,vector<vector<int>>&maze,vector<string>&ans,string s,vector<vector<bool>>&vis)
  {
      int n = maze.size();
      if (r<0 || r>=n || c<0 || c>=n || maze[r][c]==0 || 
      vis[r][c]==true) return;
      if (r==n-1 && c==n-1) {
          ans.push_back(s);
          return;
      }
      vis[r][c]=true;
      f(r+1,c,maze,ans,s+'D',vis);
      f(r,c-1,maze,ans,s+'L',vis);
      f(r,c+1,maze,ans,s+'R',vis);
      f(r-1,c,maze,ans,s+'U',vis);
      vis[r][c]=false;

  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        int n = maze.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        if (maze[0][0]==0) return ans;
        string s="";
        f(0,0,maze,ans,s,vis);
        return ans;
        
    }
};