#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(int col,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n,vector<string>&board)
{
    if (col==n)
    {
        return 1;
    }
    int a =0;
    for(int row=0;row<n;row++)
    {
        if(leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0)
    {
        leftRow[row]=1;
        upperDiagonal[n-1+col-row]=1;
        lowerDiagonal[row+col]=1;
        board[row][col]='Q';
        a +=solve(col+1,leftRow,upperDiagonal,lowerDiagonal,n,board);
        leftRow[row]=0;
        upperDiagonal[n-1+col-row]=0;
        lowerDiagonal[row+col]=0;
        board[row][col]='.';
    }
    }
    return a;
}
    int totalNQueens(int n) {
    
        vector<string>board(n,string(n,'.'));
        vector<int>leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        return solve(0,leftRow,upperDiagonal,lowerDiagonal,n,board);
    }
};