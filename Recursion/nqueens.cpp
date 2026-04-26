#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void solve(int col,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n,vector<vector<string>>&ans,vector<string>board)
{
    if (col==n)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0)
    {
        leftRow[row]=1;
        upperDiagonal[n-1+col-row]=1;
        lowerDiagonal[row+col]=1;
        board[row][col]='Q';
        solve(col+1,leftRow,upperDiagonal,lowerDiagonal,n,ans,board);
        leftRow[row]=0;
        upperDiagonal[n-1+col-row]=0;
        lowerDiagonal[row+col]=0;
        board[row][col]='.';
    }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        vector<int>leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,leftRow,upperDiagonal,lowerDiagonal,n,ans,board);
        return ans;
    }
};