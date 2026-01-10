#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int n, int m, int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& board) {
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(n, m, nrow, ncol, vis, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<char>> ans(n, vector<char>(m, 'X'));
        //first and last col
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(n, m, i, 0, vis, board);
            }

            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(n, m, i, m - 1, vis, board);
            }
        }
        //first and last row 
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(n, m, 0, j, vis, board);
            }

            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n, m, n - 1, j, vis, board);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};